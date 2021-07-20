
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,k,Min=0,Max=0,pivo;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    pivo = min(k,n-k);
    for(int i=0;i<pivo;i++) Min += a[i];
    for(int i=pivo;i<n;i++) Max += a[i];
    cout<<Max-Min<<endl;

}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}