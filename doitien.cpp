
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int mau[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

void solve(){
    int n,res=0;
    cin>>n;
    for(int i=9;i>=0;i--){
        while(n>0 && n>=mau[i]){
            res++;
            n-=mau[i];
        }
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