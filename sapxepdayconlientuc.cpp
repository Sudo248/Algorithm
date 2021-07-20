
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,l,r;
    cin>>n;
    vector<int>a(n),b;
    for(int i=0;i<n;i++) cin>>a[i];
    b = a;
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++){
        if(a[i] != b[i]){
            l = i+1;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i] != b[i]){
            r = i+1;
            break;
        }
    }
    cout<<l<<' '<<r<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}