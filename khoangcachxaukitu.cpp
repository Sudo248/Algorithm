#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int n, start, finish, res;
string s,t;
vector<string> way;
vector<bool>check;

vector<vector<int> > G;

bool cmp(string a, string b){
    int dem = 0;
    for(int i=0;i<a.length();i++){
        if(a[i] != b[i]) {
            dem++;
            if(dem > 1) return false;
        }
    }
    return true;
}

void buildGraph(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(cmp(way[i], way[j])){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
}

void BFS(){
    queue<pair<int, int> >q;
    q.push({start, 1});
    check[start] = true;
    while(q.size()){
        pair<int,int> tmp = q.front(); q.pop();
        for(int &i:G[tmp.first]){
            if(!check[i]){
                if(i == finish){
                    res = tmp.second +1;
                    return;
                }
                check[i] = true;
                q.push({i,tmp.second+1});  
            }
        }
    }
}

void solve(){

    cin >> n >> s >> t;
    way.clear();
    way.resize(n);
    G.clear();
    G.resize(n);
    check.assign(n+1, false);

    for(int i=0;i<n;i++){
        cin >> way[i];
        if(way[i] == s) start = i;
        if(way[i] == t) finish = i;
    }

    buildGraph();
    BFS();
    cout << res << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}