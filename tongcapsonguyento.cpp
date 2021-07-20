
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

bool isPrime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    for(int i=2;i<=n/2;i++){
        if(isPrime(i) && isPrime(n-i)){
            cout<<i<<' '<<n-i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}