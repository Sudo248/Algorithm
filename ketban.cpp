#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<vector<int> > G;
vector<bool>check;
int dem = 0;
void DFS(int u){
    check[u] = true;
    dem++;
    for(int &v:G[u])
    {
        if(!check[v]) DFS(v);
    }
} 

void solve(){

    int n,m;
    cin >> n >> m;
    G.clear();
    G.resize(n+1);
    check.clear();
    check.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        if(!check[i]){
            dem = 0;
            DFS(i);
            res = max(res,dem);
        }
    }
    cout << res << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}