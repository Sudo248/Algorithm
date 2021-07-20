
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define mod (int)(1e9+7)
ll C[1001][1001];

void init(){
    for(int n=0;n<=1000;n++){
        for(int k=0;k<=n;k++){
            if(k==n || k == 0) C[k][n] = 1;
            else C[k][n] = C[k-1][n-1] + C[k][n-1];
            C[k][n] %= mod;
        }
    }
}

int main(){
    faster
    init();
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        cout<<C[k][n]<<endl;
    }

    return 0;
}