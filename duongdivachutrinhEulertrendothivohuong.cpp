#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<vector<int> >G;
vector<bool>check;

void DFS(int u){
    check[u] = true;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(!check[v]){
            DFS(v);
        }
    }
}

void solve(){

    int V,E;
    cin >> V >> E;
    G.clear();
    G.resize(V+1);
    check.clear();
    check.resize(V+1);
    for(int i=0;i<E;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    DFS(1);
    int dem = 0;
    for(int i=1;i<=V;i++){
        if(!check[i]){
            cout << "0\n";
            return;
        }
        if(G[i].size() % 2) dem++;
    }

    if(dem == 0) cout << "2\n";
    else if(dem == 2) cout << "1\n";
    else cout << "0\n";

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}