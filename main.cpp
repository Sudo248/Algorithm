#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    ll n;
    cin >> n;
    string s;
    cin >> s;
    priority_queue<ll>pq;
    vector<ll>ts(27,0);
    for(char &c:s) ts[c-'A']++;

    for(size_t i=0;i<=26;i++){
        if(ts[i]){
            pq.push(ts[i]);
        }
    }

    for(size_t i=0;i<n;i++){
        ll tmp = pq.top();
        if(tmp == 0) break;
        pq.pop();
        pq.push(tmp - 1);
    }

    ll res = 0;

    while(pq.size()){
        ll tmp = pq.top(); pq.pop();
        res += tmp*tmp;
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