
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,k,res=0;;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++){
        int r = upper_bound(a.begin()+i+1,a.end(),k-a[i]) - a.begin();
        int l = lower_bound(a.begin()+i+1,a.end(),k-a[i]) - a.begin();
        res += r-l;
        
    }
    cout<<res<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}