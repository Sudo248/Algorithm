#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n,k,sum=0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        sum+=x;
    }
    
    cout << (sum%k == 0 ? "1\n" : "0\n");

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}