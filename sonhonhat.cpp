
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;


void solve(){
    int n,d;
    cin >> n >> d;
    if(9*d < n){
        cout << -1 << endl;
        return;
    }
    string res = "";
    while(n >= 9){
        res += "9";
        n-=9;
    }
    if(n) res += (n + '0');
    while(res.length() < d) res += "0";
    reverse(res.begin(), res.end());
    if(res[0] == '0'){
        res[0] = '1';
        for(int i=1;i<d;i++){
            if(res[i] != '0'){
                res[i]--;
                break;
            }
        }
    }
    cout << res << endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}