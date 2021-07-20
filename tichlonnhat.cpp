#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());

    cout << max(max(a[n-1]*a[n-2]*a[n-3],a[0]*a[1]*a[n-1]), max(a[n-1]*a[n-2], a[0]*a[1])) << endl;

}


int main(){
    faster
    solve();

    return 0;

}