#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
ll a[31][31]={0};
void init(){  
    for(int i=0;i<=25;i++) a[i][0] = 1;
    for(int i=0;i<=25;i++) a[0][i] = 1;
    a[0][0]=1;
    for(int i=0;i<=25;i++){
        for(int j=0;j<=25;j++){
            if(i!=0 && j!=0)
                a[i][j] = a[i-1][j] + a[i][j-1];
        }
    }
}
void solve(){

    int n,m;
    cin >> n >> m;
    cout << a[n][m] << endl;

}


int main(){
    faster
    init();
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}