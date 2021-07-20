#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n,x,y,z;
    cin >> n >> x >> y >>z;
    vector<int>a(n+5);
    a[1] = x;
    for(int i=2;i<=n;i++){
        if(i%2){
            a[i] = min(a[i-1]+x, a[(i+1)/2]+y+z);
        }
        else{
            a[i] = min(a[i-1]+x,a[i/2]+z);
        }
    }

    cout << a[n] << endl;
}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}