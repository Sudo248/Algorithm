#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    int a[n][n]={};
    for(int i=1;i<=n;i++){
        for(int l=0;l<n-i+1;l++){
            int r = l+i-1;
            if(i==1){
                a[l][r] = 1;

            } 
            else if(i==2){
                if(s[l]==s[r]){
                    a[l][r] = 2;
                }
                else a[l][r]=1;
            }
            else{
                a[l][r] = max(a[l+1][r],a[l][r-1]);
                if(s[l]==s[r]) a[l][r] = max(a[l][r], a[l+1][r-1]+2);
            }
        }
    }
    
    cout << n - a[0][n-1] << '\n';

}

int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}