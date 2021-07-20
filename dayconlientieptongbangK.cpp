#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    ll k;
    cin >> n >> k;
    vector<ll>a(n+1);
    a[0] = 0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    if(k==0){
        cout << "NO\n";
        return;
    }
    // for(ll i:a) cout << i << ' ';
    // cout << endl;
    for(int i=0;i<=n;i++){
        if(binary_search(a.begin(),a.end(),k+a[i])){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}