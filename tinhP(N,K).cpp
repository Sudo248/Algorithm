#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define mod (int)(1e9+7)
using namespace std;
typedef long long ll;

void solve(){

    int n,k;
    cin >> n >> k;

    if(k>n) cout << "0\n";
    else{
        ll res = 1;
        for(int i=n;i>=n-k+1;i--){
            res *= i;
            res %= mod;
        }
        cout << res << endl;
    }

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}