
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int>a(k+1),b(k+1);
    for(int i = 1; i <= k; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    int i = k;
    while(i > 0 && a[i] == n-k+i) i--;

    if(i <= 0) cout << k << endl;
    else{
        a[i]++;
        for(int j = i+1; j <= k; j++) 
            a[j] = a[j-1] + 1;
        int res = 0;
        for(int i = 1; i <= k; i++){
            if(!binary_search(b.begin(),b.end(),a[i])){
                res ++;
            }
        }
        cout << res <<endl;
    }

}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}