#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define mod int(1e9+7)
using namespace std;
typedef long long ll;

void solve(){

    int n,k;
    cin >> n >> k;
    vector<int>a(n);
    vector<ll>b(k+1);
    b[0] = 1;
    for(int &i:a) cin >> i;
    for(int i=1;i<=k;i++){
        for(int &x:a){
            if(i>=x){
                b[i] = (b[i]+b[i-x])%mod;
            }
        }
    }
    cout << b[k] << endl;
    

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}