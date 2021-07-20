#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<vector<int> >G;
vector<int>check;
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

    int n;
    cin >> n;
    G.clear();
    G.resize(n+1);
    check.clear();
    check.resize(n+1,0);
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    for(int i=1;i<=n;i++){
        if(!check[i]){
            check[i] = true;
            BFS(i);
            if(hasCycle){
                cout << "NO\n";
                return;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!check[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}