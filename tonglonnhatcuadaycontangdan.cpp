#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    int res = 0;
    cin >> n;
    vector<int>a(n), dd(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        dd[i] = a[i];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j] < a[i]){
                dd[i] = max(dd[i], dd[j] + a[i]);
            }
        }
        res = max(res,dd[i]);
    }

    // for(int i=0;i<n;i++) cout << dd[i] << ' ';

    cout << res << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}