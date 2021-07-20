
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,s;
    cin>>n>>s;
    vector<int>res(s+1,0);
    res[0]=1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        res[x] = 1;
        for(int j=s;j>=x;j--){
            if(res[j-x]) res[j]=1;
        }
    }
    if(res[s]) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}