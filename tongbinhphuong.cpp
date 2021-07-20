#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int res;

void count(int n, int tmp){
    if(n == 0) {
        res = min(res,tmp);
        return;
    }
    int x = sqrt(n);
    for(int i=x;i>=1;i--){
        if(tmp+1>= res){
            return;
        }
        count(n-(i*i),tmp+1);
    }
}

void solve(){

    int n;
    res = INT_MAX;
    cin >> n;
    count(n,0);
    cout << res << '\n';

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}