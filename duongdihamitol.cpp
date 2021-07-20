#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<vector<int> > G;
vector<bool>checked;
int V,E;
bool res;

void DFS(int u, int count){

    for(int &v: G[u]){
        if(!checked[v]){
            if(count == V){
                res = 1;
                return;
            }
            checked[v] = true;
            DFS(v, count+1);
            checked[v] = false;
        }
    }
}

void solve(){

    cin >> V >> E;
    G.clear();
    G.resize(100);
    

    for(int i = 0;i<E;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    res = 0;
    for(int i=1;i<=V;i++){
        checked.clear();
        checked.resize(100);
        checked[i] = false;
        DFS(i,1);
        if(res){
            break;
        }
    }
    cout << res << endl;

}

int main(){

    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}