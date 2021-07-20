
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,x,a,res=0;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a;
        res += a==x?1:0;
    }
    cout<<(res>0?res:-1)<<endl;

}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}