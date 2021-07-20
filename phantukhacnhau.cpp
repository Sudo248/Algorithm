
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<ll>a(n),b(n-1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>b[i];
    }
    for(int i=0;i<n-1;i++){
        if(a[i] != b[i]){
            cout<<i+1<<endl;
            return;
        }
    }
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}