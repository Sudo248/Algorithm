#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

bool isBoi2(int n){
    int tmp = 1;
    while(tmp < n) tmp*=2;
    return tmp == n;
}

void solve(){

    int n;
    cin >> n;
    cin.ignore();
    string input;
    int l = 0, r = 0;
    getline(cin,input);
    for(char &c:input){
        if(c == 'L') l++;
        else if(c == 'R') r++;
    }
    if(l == r && isBoi2(n+2)){
        cout << "Yes\n";
    }
    else cout << "No\n";


}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}