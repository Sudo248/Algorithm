
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    priority_queue<ll,vector<ll>,greater<ll> > pq;
    // priority_queue<int,vector<int> , greater<int> >a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push(x);
    }
    ll res = 0;
    while(pq.size() >= 2){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        res += (x+y);
        pq.push(x+y);
    }
    cout<<res<<endl;
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}