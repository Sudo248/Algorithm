
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    bool dd =false;
    int Max = INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0) dd = true;
        if(Max < a[i]) Max = a[i];
    }
    if(dd){
        int res = 0,sum=0;
        for(int i = 0 ; i <  n ; i ++){
            if(sum+a[i]<0){
                sum=0;
            }
            else{
                sum+=a[i];
                res = max(res,sum);
            }
        }
        cout<<res<<endl;
    }
    else{
        cout<<Max<<endl;
    }
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}