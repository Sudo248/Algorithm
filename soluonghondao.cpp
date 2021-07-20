#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define MAX 505
bool a[MAX][MAX];
int X[] = {-1,-1,-1,0,0,1,1,1};
int Y[] = {-1,0,1,-1,1,-1,0,1};

void BFS(int x, int y){
    queue<pair<int,int> >q;
    q.push({x,y});
    a[x][y] = 0;
    while(q.size()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int xx = x + X[i];
            int yy = y + Y[i];
            if(a[xx][yy]){
                a[xx][yy] = 0;
                q.push({xx,yy});
            }
        }
    }
}


void solve(){

    int n,m;
    cin >> n >> m;
    memset(a,sizeof(a),0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    int count = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]){
                BFS(i,j);
                count++;
            }
        }
    }
    cout << count << endl;
    
}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}