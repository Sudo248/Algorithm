
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define mod (int)(1e9+7)
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1,0);
    a[0]=1;
    for(int i=1;i<=n;i++){
        int x;
        if(i<=k) x=0;
        else x = i-k;
        for(int j=x;j<i;j++) {
            a[i]+=a[j];
            a[i] %= mod;
        }
    }
    cout<<a.back()<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}