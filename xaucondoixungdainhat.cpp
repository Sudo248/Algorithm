#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    int res = 1;
    for(int i=0;i<n;i++){
        int l=i,r=i;
        while(l>=0 && r < n){
            if(s[l] == s[r]) {
                res = max(res, r-l+1);
                l--;r++;
            }
            else break;
        }
    }
    for(int i=0;i<n-1;i++){
        int l=i, r = i+1;
        while(l>=0 && r<n){
            if(s[l] == s[r]) {
                res = max(res, r-l+1);
                l--;r++;
            }
            else break;
        }
    }

    cout << res << '\n';

}

int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}