#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    vector<vector<int> > G;
    G.resize(n+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin >> x;
            if(x){
                G[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
    for(int i=1; i<=n;i++){
        for(int &j:G[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
    

    



}


int main(){
    faster
    solve();

    return 0;

}