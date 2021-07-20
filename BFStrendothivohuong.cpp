
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void BFS(int i){
    
    

}

void solve(){
    int v,e,uIv,x,y;
    cin>>v>>e>>uIv;
    vector<vector<int> > G(v+1);
    vector<bool>check(1005,false);
    for(int i=0;i<e;i++){
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    // for(int i=1;i<=v;i++) sort(G[i].begin(),G[i].end());

    queue<int>q;
    q.push(uIv);
    check[uIv] = true;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        cout<<u<<' ';
        for(int j=0;j<G[u].size();j++){
            int v = G[u][j];
            if(!check[v]){
                q.push(v);
                check[v] = true;
            }
        }
    }
    cout<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}