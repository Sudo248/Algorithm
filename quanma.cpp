#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct data{
    int x,y,count;
};
int X[8] = {2,1,-1,-2,-2,-1,1,2};
int Y[8] = {1,2,2,1,-1,-2,-2,-1};

void BFS(int xST, int yST, int xEN, int yEN){
    queue<data>q;
    q.push({xST,yST,0});
    while(true){
        data tmp = q.front();q.pop();
        if(tmp.x == xEN && tmp.y == yEN){
            cout << tmp.count << endl;
            return;
        }
        for(int i=0;i<8;i++){
            int nextX = tmp.x + X[i];
            int nextY = tmp.y + Y[i];
            if(nextX >= 1 && nextX <= 8 && nextY >= 1 && nextY <= 8){
                q.push({nextX,nextY, tmp.count+1});
            }
        }
    }
}

void solve(){
    string a,b;
    cin >> a >> b;
    int xST = a[0]-'a' + 1;
    int yST = a[1]-'0';
    int xEN = b[0]-'a' + 1;
    int yEN = b[1]-'0';
    BFS(xST,yST,xEN, yEN);
}
 
 
int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();
 
    return 0;
 
}