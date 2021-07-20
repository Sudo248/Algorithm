
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    string s;
    int n;
    cin>>n>>s;
    int dd[1001][1001]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1] == s[j-1] && i!=j ){
                dd[i][j] = dd[i-1][j-1]+1;
            }
            else{
                dd[i][j] = max(dd[i-1][j],dd[i][j-1]);
            }
        }
    }
    cout<<dd[n][n]<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}