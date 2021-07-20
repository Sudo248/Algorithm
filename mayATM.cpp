
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
ll n, res = 0, ans;
ll S;
bool dd = false;
vector<ll>a;


void Try(int x){
    
    for(int i=x;i<n;i++){
        if(S >= a[i]){
            S -= a[i];
            res++;
            if(S==0){
                ans = min(ans,res);
                //cout << ans << " ** ";
                dd = true;
                
            }
            else Try(i+1);
            S += a[i];
            res--;
            
        }
    }
}

void solve(){
    cin >> n >> S;
    a.resize(n);
    ans = INT_MAX;
    res = 0;
    dd = false;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(), a.rend());
    int begin;
    for(int i=0; i < n; i++){
        if(S>=a[i]) {
            begin = i;
            break;
        }
    }
    Try(begin);
    if(!dd){
        cout << -1;
    }
    else cout << ans;
    cout << endl;
}

int main(){
    faster
    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}