
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n, res = 0;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n - 1; i++){
        int Min = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[Min]){
                Min = j;
            }
        }
        if(Min != i){
            swap(a[i],a[Min]);
            res++;
        }
    }
    cout << res << endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}