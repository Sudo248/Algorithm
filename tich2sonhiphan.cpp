#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

ll power(ll a, ll k)
{
    if(k==0) return 1;
    if (k == 1) return a;
    ll res = power(a, k/2);
    if(k % 2 == 0) return res*res;
    else return a*res*res;
}

void solve(){

    ll sum,a=0,b=0;
    string A,B;
    cin >> A >> B;
    int n = A.length();
    for(int i=0;i<A.length();i++){
        a = a + (A[i]-'0')*(power(2,n-i-1));
    }
    n = B.length();
    for(int i=0;i<B.length();i++){
        b = b + (B[i]-'0')*(power(2,n-i-1));
    }
    sum = a*b;
    
    cout << sum << endl;
}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}