#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

ll to_int(string S){
    ll res = 0;
    for(char &c:S) res= res*10+(c-'0');
    return res;
}

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    ll res = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            string tmp = "";
            for(int k=j;k<i+j;k++){
                tmp += s[k];
            }
            res += to_int(tmp);
        }
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