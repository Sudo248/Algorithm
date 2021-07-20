#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    string s;
    int k;
    cin >> k >> s;
    priority_queue<ll> pq;

    int ts[101] = {0};
    for(char i:s){
        ts[i]++;
    }
    for(int i=0;i<101;i++){
        if(ts[i]>0) pq.push(ts[i]);
    }

    while(pq.top() > 0 && k--){
        ll tmp = pq.top();
        pq.pop();
        pq.push(tmp-1);
    }

    ll res = 0;
    while(pq.size()){
        ll tmp = pq.top();
        // cout << tmp << ' ';
        pq.pop();
        res += tmp*tmp;
    }
    cout << res << endl;

}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}