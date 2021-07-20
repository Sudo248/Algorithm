#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<pair<int,int> > dsCanh;
vector<vector<int> >G;
vector<bool>check;
vector<int>RES;
int V, E, TPLT;
  
void DFS(int u){
    check[u] = true;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(!check[v]){
            DFS(v);
        }
    }
}

int tplt(int u){
    check.clear();
    check.resize(V+1,0);
    check[u] = true;
    int res = 0;

    for(int i=1;i<=V;i++){
        if(!check[i]){
            res++;
            DFS(i);
        }
    }
    return res;
}

void solve(){

    cin >> V >> E;
    G.clear();
    G.resize(V+1);

    for(int i=0;i<E;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    TPLT = tplt(0);

    for(int i=1;i<=V;i++){
        int res = tplt(i);
        if(res > TPLT) cout << i << ' ';
    }

    cout << endl;

}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}