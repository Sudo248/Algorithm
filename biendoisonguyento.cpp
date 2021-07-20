#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define MAX 10005
vector<bool> isPrime(MAX,true);
vector<vector<int> >G;
int be, en, ans, Res;

int to_int(string s){
    int res = 0;
    for(char c:s) res=res*10+(c-'0');
    return res;
}

void connect(int x){
    string s = to_string(x);
    string tmp = s;
    for(int i='1';i<='9';i++){
        tmp[0] = i;
        int y = to_int(tmp);
        if(isPrime[y] && x!=y) 
            G[x].push_back(y);
    }
    
    for(int i=1;i<=3;i++){
        tmp = s;
        for(int j='0';j<='9';j++){
            tmp[i] = j;
            int y = to_int(tmp);
            if(isPrime[y] && x!=y) 
                G[x].push_back(y);
        }
    }
}

void prepare(){
    isPrime[0]=isPrime[1] = false;
    for(int i=4;i<=MAX;i+=2) isPrime[i] = false;
    for(int i=3;i<=MAX;i+=2){
        if(isPrime[i]){
            for(int j=i+i;j<=MAX;j+=i){
                isPrime[j] = false;
            }
        }
    }

    G.resize(MAX);

    for(int i=1000;i<=MAX;i++){
        if(isPrime[i]){
            connect(i);
        }
    }

}

void BFS(int n){
    queue <pair<int, int> > st;
    st.push(make_pair(n, 0));
    vector<bool>check;
    check.resize(10000, false);
    check[n] = true;
    while (!st.empty() && ans == false) {
        pair<int, int> tg = st.front(); st.pop();
        for (int i:G[tg.first]) {
            if (ans == false && check[i] == false) {
                if (i==en) {
                    ans = true;
                    Res = tg.second+1;
                    return;
                }
                st.push(make_pair(i, tg.second + 1));
                check[i] = true;
            }
        }
    }
}

void solve(){

    ans = 0;
    Res = 0;
    cin >> be >> en;
    BFS(be);
    cout << Res << endl;



}


int main(){
    faster;
    prepare();
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}