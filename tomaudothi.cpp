#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

bool cmp(pair<int, int>a, pair<int, int>b){
    return a.second > b.second;
}

void solve(){

    int V,E,M;
    cin >> V >> E >> M;
    vector<vector<int> >G;
    vector<pair<int,int> >deg;
    G.resize(V+1,vector<int>(V+1,0));
    for(int i = 1; i <= E;i++){
        int x,y;
        cin >> x >> y;
        G[x][y] = G[y][x] = 1;
    }

    for(int i = 1;i <= V;i++){
        deg.push_back({i,0});
        for(int j = 0;j <= V;j++){
            deg.back().second += G[i][j];
        }
    }

    sort(deg.begin(),deg.end(), cmp);

    int color = 0;

    vector<bool>check(V+1, false);

    for(auto &p: deg){
        if(!check[p.first]){
            color++;
            check[p.first] = true;
            for(int i=1;i<=V;i++){
                if(G[p.first][i] == 0) check[i] = true;
            }
        }
    }
    if(color <= M) cout << "YES\n";
    else cout << "NO\n";


}

int main(){

    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}