#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<vector<int> >G;
vector<bool>check;
vector<int>bbVao;

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
    bbVao.clear();
    bbVao.resize(V+1,0);
    for(int i=0;i<E;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        bbVao[y]++;
    }
    DFS(1);
    int dem = 0;
    for(int i=1;i<=V;i++){
        if(!check[i] || G[i].size() != bbVao[i]){
            cout << "0\n";
            return;
        }
    }
    cout << "1\n";
    

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}