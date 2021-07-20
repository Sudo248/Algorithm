#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int V,E;

vector<vector<int> > G;
vector<bool>check;

void BFS(int u){
    queue<int>q;
    check[u] = true;
    q.push(u);
    while(q.size()){
        int u = q.front();q.pop();
        cout << u << ' ';
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(!check[v]){
                check[v] = true;
                q.push(v);
            }
        }
    }
}

void solve(){
    int begin;
    cin >> V >> E >> begin;
    G.clear();
    G.resize(V+1);
    check.clear();
    check.resize(V+1);
    for(int i=0;i<E;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    BFS(begin);
    cout << endl;
}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}