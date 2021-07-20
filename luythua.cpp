
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define mod (int)(1e9+7)

ll Power(int x, int y){
    if(y==0) return 1;
    if(y==1) return x;
    long long tmp=Power(x,y/2);
    if(y%2==0) return (tmp%mod)*(tmp%mod)%mod;
    return (x%mod)*(tmp*tmp%mod)%mod;
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<Power(a,b)<<endl;
    }
    


    return 0;
}