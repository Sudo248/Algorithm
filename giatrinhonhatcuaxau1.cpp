
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int dd[27]={0};
    for(int i:s) dd[i-'A']++;
    vector<ll>a;
    for(int i=0;i<27;i++){
        if(dd[i] > 0) a.push_back(dd[i]);
    }
    sort(a.rbegin(),a.rend());
    a.push_back(0);
    int i=0;
    while(n > 0 && i<a.size()){
        if(a[i] > a[i+1]){
            for(int j=0;j<=i;j++) {
                a[j]--;
                n--;
                if(n==0)  break;
            }
        }
        else i++;
        
    }
    ll sum = 0;
    for(int i=0;i<a.size();i++) sum += a[i]*a[i];
    cout << sum << endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}