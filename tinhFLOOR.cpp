
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(k < a[0]) cout<<-1<<endl;
    else cout<<upper_bound(a.begin(),a.end(),k) - a.begin()<<endl;
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}