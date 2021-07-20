
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<ll>a(n),b(n);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.rbegin(),b.rend());
    ll res = 0;
    for(int i = 0; i < n; i++) res += a[i]*b[i];

    cout <<res <<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}