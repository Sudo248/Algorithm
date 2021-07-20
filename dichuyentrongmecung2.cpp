
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int n;
int a[11][11];
bool check[11][11];
vector<string>res;

void Try(int x, int y, string way){
    if(x == n && y == n){
        res.push_back(way);
        return;
    }

    if(a[x+1][y] && !check[x+1][y]){
        check[x+1][y] = true;
        Try(x+1, y, way + "D");
        check[x+1][y] = false;
    }

    if(a[x][y+1] && !check[x][y+1]){
        check[x][y+1] = true;
        Try(x, y+1, way + "R");
        check[x][y+1] = false;
    }

    if(a[x][y-1] && !check[x][y-1]){
        check[x][y-1] = true;
        Try(x, y-1, way + "L");
        check[x][y-1] = false;
    }

    if(a[x-1][y] && !check[x-1][y]){
        check[x-1][y] = true;
        Try(x-1, y, way + "U");
        check[x-1][y] = false;
    }
    

}

void solve(){
    
    cin >> n;

    memset(a,0,sizeof(a));
    memset(check,false,sizeof(check));
    res.clear();
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    if(a[1][1] == 0 | a[n][n] == 0){
        cout << -1 << endl;
    }
    else{
        check[1][1] = true;
        Try(1,1,"");
        if(res.empty()){
            cout << -1 << endl;
        }
        else{
            sort(res.begin(),res.end());
            for(int i = 0; i < res.size(); i++){
                cout << res[i] << ' ';
            }
            cout << endl;
        }
    }


}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}