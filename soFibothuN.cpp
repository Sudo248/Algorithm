
#include <bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define mod (int)(1e9 + 7)
using namespace std;
typedef long long ll;
struct matrix
{
    ll a[2][2] = {{0, 1}, {1, 1}};
};

matrix multiple(matrix x, matrix y)
{
    matrix res;
    res.a[0][0] = (x.a[0][0] * y.a[0][0] + x.a[0][1] * y.a[1][0]) % mod;
    res.a[0][1] = (x.a[0][0] * y.a[0][1] + x.a[0][1] * y.a[1][1]) % mod;
    res.a[1][0] = (x.a[1][0] * y.a[0][0] + x.a[1][1] * y.a[1][0]) % mod;
    res.a[1][1] = (x.a[1][0] * y.a[0][1] + x.a[1][1] * y.a[1][1]) % mod;
    return res;
}

matrix poweMatrix(matrix a, ll k)
{
    if (k == 1)
        return a;
    matrix res = poweMatrix(a, k/2);
    if(k % 2 == 0) return multiple(res,res);
    else return multiple(a, multiple(res, res));
}

void solve()
{
    int n;
    cin >> n;
    matrix res;
    res = poweMatrix(res, n);

    cout << res.a[0][1] << endl;

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