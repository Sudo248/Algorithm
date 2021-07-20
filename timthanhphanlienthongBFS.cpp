#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<vector<int> >G;
vector<bool>check;

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
            }
        }
    }
}

void solve(){
    int V,E;
    cin >> V >> E;
    G.clear();
    G.resize(V+5);
    check.clear();
    check.resize(V+5);
    for(int i=0;i<E;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int dem = 0;
    for(int i=1;i<=V;i++){
        if(!check[i]){
            dem++;
            BFS(i);
        }
    }
    cout << dem << endl;
    
}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}