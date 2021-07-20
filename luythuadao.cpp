
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define mod (int)(1e9+7)
ll Power(ll x, ll y){
    if(y==1) return x;
    ll tmp=Power(x,y/2)%mod;
    if(y%2==0) return (tmp*tmp)%mod;
    return ((tmp*tmp)%mod * x)%mod;
}

void solve(){
    ll n,m,dao=0;
    cin>>n;
    m=n;
    while(m){
        dao = dao*10 + m%10;
        m/=10;
    }
    cout<<Power(n,dao)%mod<<endl;

}


int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();
    


    return 0;
}