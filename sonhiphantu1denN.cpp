
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

string toBinry(int n){
    string res = "";
    while(n){
        res = char(n%2 + '0') + res;
        n/=2;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<toBinry(i)<<' ';
    }
    cout<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}