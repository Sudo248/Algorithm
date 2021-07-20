
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,x,Min = INT_MAX,Max = INT_MIN,res=0;
    cin>>n;
    map<int,int>ts;
    for(int i=0;i<n;i++){
        cin>>x;
        ts[x]++;
        if(Max < x) Max = x;
        if(Min > x) Min = x;
    }
    for(int i=Min;i<=Max;i++){
        if(!ts[i]) res++;
    }
    cout<<res<<endl;
}


int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}