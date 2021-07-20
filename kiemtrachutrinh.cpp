#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<vector<int> >G;
vector<bool>check;
vector<int> pre;
bool hasCycle;

void BFS(int u){
    queue<pair<int,int> > q;
    q.push({u,0});
    while (!q.empty())
    {
        int u=q.front().first,pre=q.front().second;
        q.pop();
        for(int i = 0; i < G[u].size(); i++)
        {
            int v=G[u][i];
            if (check[v]&&v!=pre)
            {
                hasCycle=1;
                return;
            }
            if (check[v]==0)
            {
                check[v]=1;
                q.push({v,u});
            }
            
        }
    }
}

void solve(){
    int v,e;
    cin>>v>>e;
    hasCycle = false;
    G.clear();
    check.clear();
    G.resize(v+1);
    check.resize(v+1,false);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i=1;i<=v;i++){
        if(!check[i]){
            check[i] = true;
            BFS(i);
            if(hasCycle) break;
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