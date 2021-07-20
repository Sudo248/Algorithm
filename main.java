//This file represents several classes. It's just named *.java for syntax highlighting purposes!

//AIDL file: Defines interfaces for communicating between activities and your service.
//You can see these implemented in the service @ 'private static class ServiceStub extends IPlaybackService.Stub'

	interface IPlaybackService {

	    void stop();

	    void play();

	    void pause();

	    boolean openFile(String path);

	    long getDuration();

	    long getPosition();

	    void seek(long pos);

	    boolean isPlaying();
	}


//Service:
//Note that this is designed for playback of files located in the assets folder. You'd need to modify the 'setDataSource' method
//To enable other playback options

	public class PlaybackService extends Service {

	    private final IBinder mNinder = new ServiceStub(this);

	    private MediaPlayback mediaPlayback;

	    private AudioManager mAudioManager;

	    private MediaPlaybackHandler mPlayerHandler;

	    private AudioManager.OnAudioFocusChangeListener mAudioFocusListener = new AudioManager.OnAudioFocusChangeListener() {
	        public void onAudioFocusChange(final int focusChange) {
	            mPlayerHandler.obtainMessage(FOCUS_CHANGE, focusChange, 0).sendToTarget();
	        }
	    };

	    private static final int FOCUS_CHANGE = 10;
	    private static final int FADE_DOWN = 11;
	    private static final int FADE_UP = 12;
	    private static final int SERVER_DIED = 13;

	    private boolean mPausedByTransientLossOfFocus = false;
	    private boolean mIsSupposedToBePlaying = false;

	    @Override
	    public void onCreate() {
	        super.onCreate();

	        // Start up the thread running the service. Note that we create a
	        // separate thread because the service normally runs in the process's
	        // main thread, which we don't want to block. We also make it
	        // background priority so CPU-intensive work will not disrupt the UI.
	        final HandlerThread thread = new HandlerThread("MediaPlaybackHandler",
	                android.os.Process.THREAD_PRIORITY_BACKGROUND);
	        thread.start();

	        // Initialize the handlers
	        mPlayerHandler = new MediaPlaybackHandler(this, thread.getLooper());

	        mAudioManager = (AudioManager) getSystemService(Context.AUDIO_SERVICE);

	        Log.i("PlabackService", "MediaPlayback class instantiated");
	        mediaPlayback = new MediaPlayback();
	        mediaPlayback.setHandler(mPlayerHandler);
	    }

	    @Override
	    public void onDestroy() {
	        super.onDestroy();

	        Log.w("PlaybackService", "Destroying service");
	        mediaPlayback.release();
	    }

	    @Override
	    public IBinder onBind(Intent intent) {
	        return mNinder;
	    }


	    /**
	     * Provides an interface for dealing with playback of audio files
	     */
	    private class MediaPlayback implements MediaPlayer.OnCompletionListener, MediaPlayer.OnErrorListener {

	        private MediaPlayer mPlayer = new MediaPlayer();

	        private Handler mHandler;

	        private float mVolume;

	        private boolean mIsPlayerInitialised = false;

	        public void setHandler(Handler handler) {
	            mHandler = handler;
	        }

	        public void start() {
	            mPlayer.start();
	        }

	        public void stop() {
	            mPlayer.reset();
	            mIsSupposedToBePlaying = false;
	        }

	        /**
	         * You CANNOT use this player after calling release
	         */
	        public void release() {
	            stop();
	            mPlayer.release();
	        }

	        public void pause() {
	            mPlayer.pause();
	        }

	        public long getDuration() {
	            if (mPlayer != null && mIsPlayerInitialised) {
	                return mPlayer.getDuration();
	            }
	            return -1;
	        }

	        public long getPosition() {
	            if (mPlayer != null && mIsPlayerInitialised) {
	                return mPlayer.getCurrentPosition();
	            }
	            return 0;
	        }

	        public void seek(long whereTo) {
	            mPlayer.seekTo((int) whereTo);
	        }

	        public void setVolume(float volume)
	        {
	            mPlayer.setVolume(volume, volume);
	            this.mVolume = volume;
	        }

	        public float getVolume()
	        {
	            return mVolume;
	        }

	        public void setDataSource(String path) {
	            mIsPlayerInitialised = setDataSource(mPlayer, path);
	        }

	        private boolean setDataSource(MediaPlayer mediaPlayer, String path) {

	            try {
	                AssetFileDescriptor afd = getAssets().openFd(path);
	                mediaPlayer.reset();
	                mediaPlayer.setOnPreparedListener(null);
	                mediaPlayer.setDataSource(afd.getFileDescriptor(), afd.getStartOffset(), afd.getLength());
	                afd.close();
	                mediaPlayer.setAudioStreamType(AudioManager.STREAM_MUSIC);
	                mediaPlayer.prepare();
	                mediaPlayer.setOnCompletionListener(this);
	                mediaPlayer.setOnErrorListener(this);

	            } catch (IOException e) {
	                e.printStackTrace();
	                return false;
	            } catch (IllegalArgumentException ex) {
	                ex.printStackTrace();
	                return false;
	            } catch (SecurityException ex) {
	                ex.printStackTrace();
	                return false;
	            }
	            return true;
	        }

	        @Override
	        public void onCompletion(MediaPlayer mediaPlayer) {
	            mPlayer.release();
	            mPlayer = null;
	        }

	        @Override
	        public boolean onError(MediaPlayer mediaPlayer, int what, int extra) {

	            Log.e("PlaybackService", "Error: " + what);

	            switch (what) {
	                case MediaPlayer.MEDIA_ERROR_SERVER_DIED: {

	                    mIsPlayerInitialised = false;
	                    mPlayer.release();
	                    mPlayer = new MediaPlayer();

	                    mHandler.sendMessageDelayed(mHandler.obtainMessage(SERVER_DIED), 2000);
	                    return true;
	                }
	            }

	            return false;
	        }
	    }

	    public void stop() {

	        //Todo: Fade down nicely

	        synchronized (this) {
	            if (mediaPlayback != null && mediaPlayback.mIsPlayerInitialised) {
	                mediaPlayback.stop();
	            }
	        }
	    }

	    public void play() {
	        synchronized (this) {
	            mAudioManager.requestAudioFocus(mAudioFocusListener, AudioManager.STREAM_MUSIC, AudioManager.AUDIOFOCUS_GAIN);
	            if (mediaPlayback.mIsPlayerInitialised) {
	                mediaPlayback.start();
	                mPlayerHandler.removeMessages(FADE_DOWN);
	                mPlayerHandler.sendEmptyMessage(FADE_UP);
	                mIsSupposedToBePlaying = true;
	            }
	        }
	    }

	    public void pause() {

	        //Todo: Fade down nicely

	        synchronized (this) {
	            mPlayerHandler.removeMessages(FADE_UP);
	            if (mIsSupposedToBePlaying) {
	                mediaPlayback.pause();
	                mIsSupposedToBePlaying = false;
	                mPausedByTransientLossOfFocus = false;
	            }
	        }
	    }

	    public boolean openFile(String path) {
	        synchronized (this) {
	            if (path == null) {
	                return false;
	            }
	            mediaPlayback.setDataSource(path);
	            if (mediaPlayback.mIsPlayerInitialised) {
	                return true;
	            }
	            stop();
	            return false;
	        }
	    }

	    public long getDuration() {
	        synchronized (this) {
	            if (mediaPlayback != null && mediaPlayback.mIsPlayerInitialised) {
	                return mediaPlayback.getDuration();
	            }
	        }
	        return -1;
	    }

	    public long getPosition() {
	        synchronized (this) {
	            if (mediaPlayback != null && mediaPlayback.mIsPlayerInitialised) {
	                return mediaPlayback.getPosition();
	            }
	        }
	        return 0;
	    }

	    public void seek(long pos) {
	        synchronized (this) {
	            if (mediaPlayback != null && mediaPlayback.mIsPlayerInitialised) {
	                if (pos < 0) {
	                    pos = 0;
	                } else if (pos > mediaPlayback.getDuration()) {
	                    pos = mediaPlayback.getDuration();
	                }
	                mediaPlayback.seek(pos);
	            }
	        }
	    }
	    
	    private final class MediaPlaybackHandler extends android.os.Handler {

	        private final WeakReference<PlaybackService> _service;
	        private float mCurrentVolume = 0.8f;

	        public MediaPlaybackHandler(final PlaybackService service, final Looper looper) {
	            super(looper);
	            _service = new WeakReference<>(service);
	            MediaPlayback mediaPlayback = _service.get().mediaPlayback;
	            if (mediaPlayback != null) {
	                mCurrentVolume = mediaPlayback.getVolume();
	            }
	        }

	        @Override
	        public void handleMessage(Message msg) {
	            final PlaybackService service = _service.get();
	            if (service == null) {
	                return;
	            }

	            switch (msg.what) {
	                case FOCUS_CHANGE: {
	                    switch (msg.arg1) {
	                        case FADE_DOWN:
	                            mCurrentVolume -= .05f;
	                            if (mCurrentVolume > .2f) {
	                                sendEmptyMessageDelayed(FADE_DOWN, 10);
	                            } else {
	                                mCurrentVolume = .2f;
	                            }
	                            service.mediaPlayback.setVolume(mCurrentVolume);
	                            break;
	                        case FADE_UP:
	                            //Todo: Only fade up to original volume
	                            mCurrentVolume += .01f;
	                            if (mCurrentVolume < 1.0f) {
	                                sendEmptyMessageDelayed(FADE_UP, 10);
	                            } else {
	                                mCurrentVolume = 1.0f;
	                            }
	                            service.mediaPlayback.setVolume(mCurrentVolume);
	                            break;
	                        case AudioManager.AUDIOFOCUS_LOSS:
	                            if (service.mIsSupposedToBePlaying) {
	                                service.mPausedByTransientLossOfFocus = false;
	                            }
	                            service.pause();
	                            break;
	                        case AudioManager.AUDIOFOCUS_LOSS_TRANSIENT_CAN_DUCK:
	                            removeMessages(FADE_UP);
	                            sendEmptyMessage(FADE_DOWN);
	                            break;
	                        case AudioManager.AUDIOFOCUS_LOSS_TRANSIENT:
	                            if (service.mIsSupposedToBePlaying) {
	                                service.mPausedByTransientLossOfFocus = true;
	                            }
	                            service.pause();
	                            break;
	                        case AudioManager.AUDIOFOCUS_GAIN:
	                            if (!service.mIsSupposedToBePlaying
	                                    && service.mPausedByTransientLossOfFocus) {
	                                service.mPausedByTransientLossOfFocus = false;
	                                mCurrentVolume = 0f;
	                                service.mediaPlayback.setVolume(mCurrentVolume);
	                                service.play(); // also queues a fade-in
	                            } else {
	                                removeMessages(FADE_DOWN);
	                                sendEmptyMessage(FADE_UP);
	                            }
	                            break;
	                        default:
	                            //App.log("PlaybackService: " +  "Unknown audio focus change code");
	                    }
	                    break;
	                }
	            }
	        }
	    }

	    private static class ServiceStub extends IPlaybackService.Stub {

	        private final WeakReference<PlaybackService> _service;

	        private ServiceStub(final PlaybackService service) {
	            _service = new WeakReference<>(service);
	        }

	        @Override
	        public void stop() throws RemoteException {
	            _service.get().stop();
	        }

	        @Override
	        public void play() throws RemoteException {
	            _service.get().play();
	        }

	        @Override
	        public void pause() throws RemoteException {
	            _service.get().pause();
	        }

	        @Override
	        public boolean openFile(String path) throws RemoteException {
	            return _service.get().openFile(path);
	        }

	        @Override
	        public long getDuration() throws RemoteException {
	            return _service.get().getDuration();
	        }


	        @Override
	        public long getPosition() throws RemoteException {
	            return _service.get().getPosition();
	        }

	        @Override
	        public void seek(long pos) throws RemoteException {
	            _service.get().seek(pos);
	        }

	        @Override
	        public boolean isPlaying() {
	            return _service.get().mIsSupposedToBePlaying;
	        }
	    }

	}


//Utils class:
//Provides convenience methods for interacting with the service & silently handling exceptions

	public class PlaybackUtils {

	    public static void openFile(String path) {
	        if (ServiceUtils.sService == null) {
	            return;
	        }
	        try {
	            ServiceUtils.sService.openFile(path);
	        } catch (RemoteException e) {
	            e.printStackTrace();
	        }
	    }

	    public static void play() {
	        if (ServiceUtils.sService == null) {
	            return;
	        }
	        try {
	            ServiceUtils.sService.play();
	        } catch (RemoteException e) {
	            e.printStackTrace();
	        }
	    }

	    public static void pause() {
	        if (ServiceUtils.sService == null) {
	            return;
	        }
	        try {
	            ServiceUtils.sService.pause();
	        } catch (RemoteException e) {
	            e.printStackTrace();
	        }
	    }

	    public static void stop() {
	        if (ServiceUtils.sService == null) {
	            return;
	        }
	        try {
	            ServiceUtils.sService.stop();
	        } catch (RemoteException e) {
	            e.printStackTrace();
	        }
	    }

	    public static long getDuration() {

	        if (ServiceUtils.sService != null) {
	            try {
	                return ServiceUtils.sService.getDuration();
	            } catch (RemoteException e) {
	                e.printStackTrace();
	            }
	        }
	        return 0;
	    }

	    public static long getPosition() {

	        if (ServiceUtils.sService != null) {
	            try {
	                return ServiceUtils.sService.getPosition();
	            } catch (RemoteException e) {
	                e.printStackTrace();
	            }
	        }
	        return 0;
	    }

	    public static boolean isPlaying() {
	        if (ServiceUtils.sService != null) {
	            try {
	                return ServiceUtils.sService.isPlaying();
	            } catch (final RemoteException e) {
	                e.printStackTrace();
	            }
	        }
	        return false;
	    }

	    public static void seek(long position) {
	        if (ServiceUtils.sService != null) {
	            try {
	                ServiceUtils.sService.seek(position);
	            } catch (RemoteException e) {
	                e.printStackTrace();
	            }
	        }
	    }
	}


//ServiceUtils class.
//Provides convenience methods for binding to the service
	public class ServiceUtils {

	    private static final String TAG = "ServiceUtils";

	    public static IPlaybackService sService = null;

	    private static final WeakHashMap<Context, ServiceBinder> sConnectionMap;

	    static {
	        sConnectionMap = new WeakHashMap<>();
	    }

	    /**
	     * @param context  The {@link Context} to use
	     * @param callback The {@link ServiceConnection} to use
	     * @return The new instance of {@link ServiceToken}
	     */
	    public static ServiceToken bindToService(final Context context, final ServiceConnection callback) {
	        Activity realActivity = ((Activity) context).getParent();
	        if (realActivity == null) {
	            realActivity = (Activity) context;
	        }
	        final ContextWrapper contextWrapper = new ContextWrapper(realActivity);
	        contextWrapper.startService(new Intent(contextWrapper,
	                PlaybackService.class));
	        final ServiceBinder binder = new ServiceBinder(callback);
	        if (contextWrapper.bindService(
	                new Intent().setClass(contextWrapper, PlaybackService.class),
	                binder, 0)) {
	            sConnectionMap.put(contextWrapper, binder);
	            return new ServiceToken(contextWrapper);
	        }
	        return null;
	    }

	    /**
	     * @param token The {@link ServiceToken} to unbind from
	     */
	    public static void unbindFromService(final ServiceToken token) {
	        if (token == null) {
	            return;
	        }
	        final ContextWrapper mContextWrapper = token.mWrappedContext;
	        final ServiceBinder mBinder = sConnectionMap.remove(mContextWrapper);
	        if (mBinder == null) {
	            return;
	        }
	        mContextWrapper.unbindService(mBinder);
	        if (sConnectionMap.isEmpty()) {
	            sService = null;
	        }
	    }

	    public static final class ServiceBinder implements ServiceConnection {
	        private final ServiceConnection mCallback;

	        public ServiceBinder(final ServiceConnection callback) {
	            mCallback = callback;
	        }

	        @Override
	        public void onServiceConnected(final ComponentName className, final IBinder service) {
	            sService = IPlaybackService.Stub.asInterface(service);
	            if (mCallback != null) {
	                mCallback.onServiceConnected(className, service);
	            }
	        }

	        @Override
	        public void onServiceDisconnected(final ComponentName className) {
	            if (mCallback != null) {
	                mCallback.onServiceDisconnected(className);
	            }
	            sService = null;
	        }
	    }

	    public static final class ServiceToken {
	        public ContextWrapper mWrappedContext;

	        /**
	         * Constructor of <code>ServiceToken</code>
	         *
	         * @param context The {@link ContextWrapper} to use
	         */
	        public ServiceToken(final ContextWrapper context) {
	            mWrappedContext = context;
	        }
	    }

	}


//MainActivity:
//An Activity to demonstrate binding to the service.
	public class MainActivity extends Activity implements ServiceConnection {

	    private ServiceUtils.ServiceToken mToken;

	    @Override
	    protected void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);

	        //Let the device know that we're playing music, and volume controls should affect the music stream
	        setVolumeControlStream(AudioManager.STREAM_MUSIC);

	        //Bind to our Music Service. This is where the magic happens!
	        mToken = ServiceUtils.bindToService(this, this);


	        Button loadFileButton = (Button) findViewById(R.id.load_button);
	        loadFileButton.setOnClickListener(new View.OnClickListener() {
	            @Override
	            public void onClick(View v) {
	                if (PlaybackUtils.isPlaying()) {
	                    PlaybackUtils.stop();
	                }
	                PlaybackUtils.openFile("my_awesome_file.mp3");
	            }
	        });

	        Button playPauseButton = (Button) findViewById(R.id.play_pause_button);
	        playPauseButton.setOnClickListener(new View.OnClickListener() {
	            @Override
	            public void onClick(View v) {

	                //Todo: Make sure we've loaded a file before attempting to play or pause!
	                if (!PlaybackUtils.isPlaying()) {
	                    PlaybackUtils.play();
	                } else {
	                    PlaybackUtils.pause();
	                }
	            }
	        });
	    }

	    @Override
	    public void onDestroy() {

	        //The activity is being destroyed. We should unbind from our service
	        if (mToken != null) {
	            ServiceUtils.unbindFromService(mToken);
	            mToken = null;
	        }
	        super.onDestroy();
	    }

	    @Override
	    public void onServiceConnected(ComponentName componentName, IBinder iBinder) {
	        //Hooray, we've connected to our service.
	        //If we've arrived here, we should be able to make any calls via our PlaybackUtils class, and expect the service to
	        //respond accordingly
	    }

	    @Override
	    public void onServiceDisconnected(ComponentName componentName) {
	        //The service is disconnected.. We don't really care about this.. do we?
	    }
	}


//Open source license:
Copyright 2013 Andrew Neal

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.