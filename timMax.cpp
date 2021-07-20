
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define mod (int)(1e9+7)

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll res = 0;
    for(int i=1;i<n;i++){
        res = res%mod + (a[i]*i) % mod;
    }
    cout<<res%mod<<endl;
    
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}