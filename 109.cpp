
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<vector<int> >G(1003);
vector<bool>check(1003);
bool hasCycle;
int dinh;

void DFS(int u,int dem){
    if(hasCycle) return;
    check[u] = true;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(!check[v]){
            DFS(v,dem+1);
        }
        else if(dem == dinh){
                hasCycle = true;
                return;
            }
    }
}

void solve(){
    int v,e;
    cin>>v>>e;
    dinh = v;
    hasCycle = false;
    for(int i=1;i<1003;i++) G[i].clear();
    
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=v;i++){
        if(!check[i]){
            DFS(i,1);
            if(hasCycle) break;
            for(int i=1;i<1003;i++) check[i] = false;
        }
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