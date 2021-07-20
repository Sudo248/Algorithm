#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    int l = 0, r = 0;
    int a,b;
    char c;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        if(c == 'L') l++;
        else if(c == 'R') r++;
    }
    if(l == r && n%2==0){
        cout << "1\n";
    }
    else cout << "0\n";
}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}