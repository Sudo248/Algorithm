#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n,m;
    cin >> n >> m;
    vector<int>a(n),b(m), c(n+m-1,0);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    for(int i=0;i<n;i++){
        if(a[i] == 0) continue;
        for(int j=0;j<m;j++){
            c[i+j] += a[i]*b[j];
        }
    }

    for(int i:c) cout << i << ' ';
    cout << endl;

}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}