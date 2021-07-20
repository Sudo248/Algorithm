#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n,m;
    cin >> n >> m;
    int a[n+5][m+5] = {0}, b[n+5][m+5]={0};

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1){
                b[i][j] = b[i][j-1] + a[i][j];
            }
            else if(j==1){
                b[i][j] = b[i-1][j] + a[i][j];
            }
            else b[i][j] = min(b[i-1][j], min(b[i][j-1], b[i-1][j-1])) + a[i][j];
        }
    }

    cout << b[n][m] << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}