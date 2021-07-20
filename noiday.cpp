#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define mod int(1e9+7)
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push(x);
    }
    ll res = 0;
    while(pq.size() >= 2){
        ll x = pq.top();
        pq.pop();
        ll y = pq.top();
        pq.pop();
        ll e = (x+y) % mod; 
        res += e;
        res %= mod;
        pq.push(e);
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