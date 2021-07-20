
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
ll dd[105][25005]={0};
void solve(){
    int c,n;
    cin>>c>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
            if(j>=a[i]){
                dd[i][j] = max(dd[i-1][j],dd[i-1][j-a[i]]+a[i]);
            }
            else dd[i][j] = dd[i-1][j];
        }
    }
    cout<<dd[n][c]<<endl;
}

int main(){
    faster
    solve();

    return 0;
}