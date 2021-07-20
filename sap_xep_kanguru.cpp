#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int y=n/2-1,x = n-1, count =0;
    while(y >= 0 && x >= n/2){
        if(a[x] >= 2*a[y]){
            count++;
            x--;y--;
        }
        else y--;
    }
    cout << n - count << endl;

}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}