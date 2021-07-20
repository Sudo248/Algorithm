
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;



void solve(){
    int n,m;
    int res[105][105]={0},a[105][105];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    res[1][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i != 1 || j != 1){
                res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
    }
    
    cout<<res[n][m]<<endl;
    
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}