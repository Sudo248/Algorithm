
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<vector<int> >G(1003);
vector<bool>check(1003);
vector<int>trace(1003);

void BFS(int u,int v){
    queue<int> q;
    q.push(u);
    check[u] = true;

    while(q.size()){
        if(check[v]) return;
        int a = q.front();
        q.pop();
        for(int i=0;i<G[a].size();i++){
            int b = G[a][i];
            if(!check[b]){
                trace[b] = a;
                q.push(b);
                check[b] = true;
            }
        }
    }
}

void solve(){
    int v,e,a,b;
    cin>>v>>e>>a>>b;
    for(int i=1;i<1003;i++) G[i].clear();
    for(int i=1;i<1003;i++) check[i] = false;
    for(int i=1;i<1003;i++) trace[i] = 0;

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    BFS(a,b);
    if(!check[b]){
        cout<<-1<<endl;
    }
    else {
        vector<int>res;
        while(b != a){
            res.push_back(b);
            b = trace[b];
        }
        res.push_back(a);
        for(int i = res.size() - 1; i >= 0; i--){
            cout<<res[i]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}