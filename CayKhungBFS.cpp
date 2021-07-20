#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct edg{
    int u,v;
};

vector<vector<int> >G;
vector<edg> tree;
vector<bool>check;
int V,E,be;

void BFS(int u){
    queue<int>q;
    q.push(u);
    check[u] = true;
    while(q.size()){
        int u = q.front();q.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(!check[v]){
                check[v] = true;
                q.push(v);
                tree.push_back({u,v});           
            }
        }
    }
}

void solve(){
    cin >> V >> E >> be;
    G.clear();
    G.resize(V+1);
    check.assign(V+1,false);
    tree.clear();
    for(int i=0;i<E;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    BFS(be);
    if(tree.size() < V-1) cout << "-1\n";
    else{
        for(edg &i:tree){
            cout << i.u << ' ' << i.v << endl;
        }
    }

    

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}