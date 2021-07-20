#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    string s1,s2;
    cin >> s1 >> s2;
    int res[105][105]={0};
    for(int i=0;i<=s1.length();i++) res[i][0] = i;
    for(int i=0;i<=s2.length();i++) res[0][i] = i;
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[i-1] == s2[j-1]){
                res[i][j] = res[i-1][j-1];
            }
            else{
                res[i][j] = min(res[i-1][j], min(res[i-1][j-1], res[i][j-1]))+1;
            }
        }
    }
    cout << res[s1.length()][s2.length()] << endl;

}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}