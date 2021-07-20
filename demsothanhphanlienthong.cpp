
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<vector<int> >G(1003);
vector<bool>check(1003);

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
    int v,e,res=0;;
    cin>>v>>e;
    for(int i=1;i<1003;i++) G[i].clear();
    for(int i=1;i<1003;i++) check[i] = false;

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=v;i++){
        if(!check[i]){
            res++;
            DFS(i);
        }
    }
    cout<<res<<endl;
    
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}