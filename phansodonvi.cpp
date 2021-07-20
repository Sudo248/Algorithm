#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void phan_so_don_vi(ll tu, ll mau){
    if(mau%tu == 0){
        cout << "1/" << mau/tu << "\n";
        return;
    }

    ll x = mau/tu + 1;
    cout << "1/" << x << " + ";
    phan_so_don_vi(tu*x - mau, mau*x);
}

void solve(){

    ll tu,mau;
    cin >> tu >> mau;
    phan_so_don_vi(tu, mau);

}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}