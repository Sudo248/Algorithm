#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int prime[]={2,3,5,7,11,13,17,19,23,29,31};
int n;
ll res;
void Try(int i, ll ans, ll uoc){
    if(uoc > n) return;
    if(uoc == n){
        res = min(res, ans);
    }
    for(int j=1;j<=60;j++){
        if(ans*prime[i] > res) break;
        ans *= prime[i];
        Try(i+1, ans, uoc*(j+1));
    }
}

void solve(){

    cin >> n;
    res = 1e18;
    Try(0,1,1);
    cout << res << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}