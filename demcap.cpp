
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    ll n,m,d0a = 0,d1a = 0,d0b = 0,d1b = 0,d2b = 0,res = 0;
    cin>>n>>m;
    vector<int>a(n),b(m),RES(1001,-1);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i] == 1) d1a++;
        else if(a[i] == 0) d0a++;
    }
    for(int i=0;i<m;i++) {
        cin>>b[i];
        if(b[i] == 1) d1b++;
        else if(b[i] == 0) d0b++;
        else if(b[i] == 2) d2b++;
    }
    sort(b.begin(),b.end());
    res = d0b * (n - d0a) + d1b * (n - d0a - d1a);
    
    for(int i=0;i<n;i++){
        int pos = m,dem = 0;
        if(RES[a[i]] != -1) res += RES[a[i]];
        else if(a[i] == 2){
            pos = lower_bound(b.begin(),b.end(),5) - b.begin();
        }
        else if(a[i] == 3){
            dem += d2b;
            pos = lower_bound(b.begin(),b.end(),4) - b.begin();
        }
        else if(a[i] > 3){
            pos = lower_bound(b.begin(),b.end(),a[i]+1) - b.begin(); 
        }
        if(pos < m){
            dem = dem + m - pos;
            res += dem;
            RES[a[i]] = dem;
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