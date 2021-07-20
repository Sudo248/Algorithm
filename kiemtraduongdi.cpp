#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<vector<int> >G;
vector<bool>check;

void BFS(int begin, int end){
    queue<int>q;
    q.push(begin);
    check[begin] = true;
    while(q.size()){
        int u = q.front();q.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(!check[v]){
                check[v] = true;
                if(v == end) return;
                q.push(v);
            }
        }
    }
}

void solve(){
    int V,E,Q;
    cin >> V >> E;
    G.clear();
    G.resize(V+1);
    for(int i=0;i<E;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cin >> Q;
    for(int i=0;i<Q;i++){
        int x,y;
        cin >> x >> y;
        check.clear();
        check.resize(V+1,false);
        BFS(x,y);
        if(check[y]) cout << "YES\n";
        else cout << "NO\n";
    }

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}