#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<vector<int> >G;
vector<int>check;
int n,res;

void DFS(int u, int deep){
    res = max(res, deep);
    check[u] = true;
    for(int &v : G[u]){
        if(!check[v]){
            DFS(v, deep + 1);
        }
    }
}

void solve(){

    cin >> n;
    G.assign(n+1, vector<int>());
    check.assign(n+1,false);
    for(int i=1;i<n;i++){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
    }
    res = 0;
    DFS(1,0);
    cout << res << endl;


}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}