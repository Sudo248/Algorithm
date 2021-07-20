#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    string s;
    cin >> s;
    int i = s.length()-1;
    while(i>=0){
        if(s[i] == '0') s[i] = '1';
        else{
            s[i] = '0';
            break;
        }
        i--;
    }
    cout << s << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}