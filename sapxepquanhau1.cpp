
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int h[11],c[11],nguoc[22],xuoi[22];
int res,n;

void Try(int i){
    for(int j=1;j<=n;j++){
        if(!h[j] && !c[j] && !nguoc[i-j+n] && !xuoi[i+j-1]){
            h[j] = true;
            c[j] = true;
            nguoc[i-j+n] = true;
            xuoi[i+j-1] = true;
            if(i==n){
                res++;
            }
            else Try(i+1);
            h[j] = false;
            c[j] = false;
            nguoc[i-j+n] = false;
            xuoi[i+j-1] = false;
        }
    }
}

void solve(){
    cin>>n;
    res=0;
    for(int i=0;i<11;i++){
        c[i]=0;
        h[i]=0;
    }
    for(int i=0;i<22;i++){
        nguoc[i]=0;
        xuoi[i]=0;
    }
    Try(1);
    cout<<res<<endl;



}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}