
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<int>Prime;

void init(){
    
    vector<bool>dd(300,true);
    Prime.push_back(2);
    for(int i=4;i<300;i+=2) dd[i] = false;

    for(int i=3;i<300;i+=2){
        if(dd[i]){
            Prime.push_back(i);
            for(int j = i*i; j < 300; j += i){
                dd[j] = false;
            }
        }
    }
}

vector<vector<int> >RES;
vector<int>res;
bool dd;
void Try(int begin,int end, int s,int n){
    for(int i = begin; i <= end; i++){
        int x = Prime[i];
        if(s >= x){
            res.push_back(x);
            if(s-x==0 && res.size() == n){

                RES.push_back(res);
                
            }
            else Try(i+1,end,s-x,n);
            res.pop_back();
        }
    }
}

void solve(){
    int n,p,s;
    cin >> n >> p >> s;
    RES.clear();
    int begin = lower_bound(Prime.begin(),Prime.end(),p) - Prime.begin();
    int end = lower_bound(Prime.begin(),Prime.end(),s) - Prime.begin();
    
    res.clear();
    Try(begin+1,end,s,n);

    cout << RES.size() << endl;

    // for(int i = 0; i < RES.size(); i++){
    //     sort(RES[i].begin(), RES[i].end());
    // }
    sort(RES.begin(),RES.end());

    for(int i=0;i<RES.size();i++){

        for(int j=0;j<RES[i].size();j++){
            cout<<RES[i][j] <<' ';
        }

        cout<<endl;
    }

}

int main(){
    faster
    init();
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}