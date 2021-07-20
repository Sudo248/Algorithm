
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,x,pos=0;
    cin>>n>>x;
    vector<int>a(n);
    
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i] == x) pos = i+1;
    }
    cout<<pos<<endl;


}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}