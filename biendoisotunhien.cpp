#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    queue<pair<int, int> > q;
    set<int>checked;
    q.push({n,0});
    while(true){
        auto tmp = q.front(); q.pop();
        if(tmp.first == 1){
            cout << tmp.second << endl;
            return;
        }
        if(tmp.first == 2){
            cout << tmp.second +1 << endl;
            return;
        }
        int x = sqrt(tmp.first);

        if(checked.find(tmp.first-1) == checked.end()){
            q.push({tmp.first - 1, tmp.second+1});
            checked.insert(tmp.first-1);
        }
        if(x*x == tmp.first && checked.find(x) == checked.end()){
            q.push({x, tmp.second+1});
            checked.insert(x);
        }
        else{
            for(int i=2;i<=x;i++){
                if(tmp.first % i==0 && checked.find(tmp.first/i) == checked.end()){
                    q.push({tmp.first/i, tmp.second+1});
                    checked.insert(tmp.first/i);
                }
            }
        }

    }
}

int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}