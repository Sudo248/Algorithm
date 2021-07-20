
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;


int main(){
    faster
    int t;
    cin>>t;
    while(t--) {
        ll n,k,res=0;
        cin>>n>>k;
        while(k){
            res++;
            if(k%2) break;
            k/=2;
        }
        cout<<res<<endl;
    }


    return 0;
}