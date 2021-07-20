#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<vector<int> > G;
vector<bool> check;
vector<pair<int,int> > dsCanh, canhcau;
int V,E,TPLT;

void init(){
    dsCanh.clear();
    canhcau.clear();
    G.clear();
    check.clear();
    G.resize(V+1);
    check.resize(V+1,false);
}

void BFS(int u){
    queue<int>q;
    q.push(u);
    check[u] = true;
    while(q.size()){
        u = q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(!check[v]){
                check[v] = true;
                q.push(v);
            }
        }
    }
}

int tplt(){
    int res = 0;
    check.clear();
    check.resize(V+1,false);
    for(int i=1;i<=V;i++){
        if(!check[i]) {
            res++;
            BFS(i);
        }
        
    }
    return res;
}

void kiemTraCanh(int a){
    G.clear();
    G.resize(V+1);
    for(int i=0;i<E;i++){
        if(i!=a){
            int x = dsCanh[i].first;
            int y = dsCanh[i].second;
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }
    int tmp = tplt();
    if(tmp > TPLT){
        if(dsCanh[a].first < dsCanh[a].second){
            canhcau.push_back(dsCanh[a]);
        }else{
            canhcau.push_back({dsCanh[a].second, dsCanh[a].first});
        }
    }
}

void solve(){
    cin >> V >> E;
    init();
    for(int i=0;i<E;i++){
        int x,y;
        cin >> x >> y;
        dsCanh.push_back({x,y});
        G[x].push_back(y);
        G[y].push_back(x);
    }
    TPLT = tplt();

    for(int i = 0 ; i < E; i++){
        kiemTraCanh(i);
    }

    sort(canhcau.begin(), canhcau.end());
    for(int i=0;i<canhcau.size();i++){
        cout << canhcau[i].first << ' ' << canhcau[i].second << ' ';
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