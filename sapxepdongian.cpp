#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n,res=1;
    cin >> n;
    vector<int>a(n),b(n+1,0);
    for(int &i:a) {
        cin >> i;
        if(b[i-1]){
            b[i]=b[i-1]+1;
            res = max(res,b[i]);
        }
        else b[i] = 1;
    }
    cout << n - res << endl;
}


int main(){
    faster
    solve();

    return 0;

}