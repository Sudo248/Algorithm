#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int X[] = {-1,0,1,1,1,0,-1,-1};
int Y[] = {-1,-1,-1,0,1,1,1,0};

vector<vector<char> >G;
int res = 0;
int n,m;

void BFS(int x, int y){
    queue<pair<int,int> >q;
    q.push({x,y});
    G[x][y] = '.';
    while(q.size()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int xx = x + X[i];
            int yy = y + Y[i];
            if(xx >= 0 && yy >= 0 && xx < n && yy < m && G[xx][yy] == 'W'){
                q.push({xx,yy});
                G[xx][yy] = '.';
            }
        }
    }
}

void solve(){

    cin >> n >> m;
    G.resize(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> G[i][j];
        }
    }
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(G[i][j] == 'W'){
                BFS(i,j);
                res++;
            }
        }
    }
    cout << res << endl;


}

int main(){

    faster
    solve();

    return 0;
}