
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,x,a;
    bool dd = false;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==x) dd = true;
    }
    if(dd) cout<<1<<endl;
    else cout<<-1<<endl;

}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}