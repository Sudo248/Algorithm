
#include <bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define mod (int)(1e9 + 7)
using namespace std;
typedef long long ll;
struct matrix
{
    ll a[11][11] = {0};
};
int n;
matrix multiple(matrix x, matrix y)
{
    matrix res;
    for(int i=0;i<n;i++){
        for(int j=0;j<n; j++){
            for(int k=0;k< n; k++){
                res.a[i][j] = (res.a[i][j] + (x.a[i][k] * y.a[k][j])%mod) % mod;
            }
        }
    }
    return res;
}

matrix poweMatrix(matrix a, ll k)
{
    
    if (k == 1) return a;
    matrix res = poweMatrix(a, k/2);
    if(k % 2 == 0) return multiple(res,res);
    else return multiple(a, multiple(res, res));
}

void solve()
{
    ll k;
    cin >> n >> k;
    matrix a;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a.a[i][j];
        }
    }
    matrix res = poweMatrix(a, k);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << res.a[i][j] << ' ';
        }
        cout << endl;
    }

}

int main()
{
    faster
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}