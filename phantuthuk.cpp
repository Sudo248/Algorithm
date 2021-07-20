
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n+m);
    for(int i=0;i<n+m;i++) cin>>a[i];
    sort(a.begin(),a.end());
    cout<<a[k-1]<<endl;
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}