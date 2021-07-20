
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,m,x,Min = INT_MAX,Max = INT_MIN;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>x;
        Max = max(Max,x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        Min = min(Min,x);
    }
    cout<<ll(Max)*Min<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}