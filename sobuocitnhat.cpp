
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,Max=0;
    cin>>n;
    vector<int>a(n),res(n,1);
    for(int i = 0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i] >= a[j]){
                res[i] = max(res[i],res[j]+1);
            }
        }
        Max = max(Max,res[i]);
    }
    cout<<n-Max<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}