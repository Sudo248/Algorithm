#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<vector<int> >G;
vector<int>check;
bool hasCycle;

void DFS(int u){
    check[u] = true;
    for(int &v:G[u]){
        if(check[v]==0) {
            DFS(v);
        }
        else if(check[v] == 1){
            hasCycle = true;
        }
    }
    check[u] = 2;
}

void solve(){
    int V,E;
    cin>>V>>E;
    hasCycle = false;
    G.clear();
    G.resize(V+1);
    check.clear();
    check.resize(V+1,false);
    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
    }
    for(int i=1;i<=V;i++){
        if(!check[i])
            DFS(i);
        if(hasCycle) break;
    }
    if(hasCycle) cout<<"YES\n";
    else cout<<"NO\n"; 
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}