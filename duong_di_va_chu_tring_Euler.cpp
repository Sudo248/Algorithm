#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<vector<int> > G;
vector<bool>check;
int begin, count;

void DFS(int u){
    check[u] = false;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i]; 
        if(check[v]){
            DFS(v);
        }
    }
}

void solve(){

    int V,E;
    cin >> V >> E;
    G.resize(V);
    for(int i=0;i<E;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    



}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}