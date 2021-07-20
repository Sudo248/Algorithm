
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n),b;
    for(int i=0;i<n;i++) cin>>a[i];
    b=a;
    sort(a.begin(),a.end());
    bool dd = true;
    for(int i=0;i<n/2;i++){
        if(a[i] != b[i]){
            if(a[i] != b[n-1-i]){
                dd=false;
                break;
            }
        }
        else{
            if(a[n-1-i] != b[n-1-i]){
                dd=false;
                break;
            }
        }
    }
    if(dd) cout<<"Yes\n";
    else cout<<"No\n";

}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}