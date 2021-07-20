#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<ll>RES(501,-1);

void BDN(int n){
    ll res;
    queue<ll>q;
    q.push(9);
    while(q.size()){
        res = q.front();q.pop();
        if(res % n == 0){
            RES[n] = res;
            return;
        }
        q.push(res*10);
        q.push(res*10+9);
    }
    return;
}

void solve(){
    int n;
    cin>>n;
    if(RES[n] == -1){
        BDN(n);
    }  
    cout << RES[n] <<endl;
    
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}