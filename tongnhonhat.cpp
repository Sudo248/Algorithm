
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    long long x=0,y=0;
    while(a.size()){
        x = x*10+a.back();
        a.pop_back();
        if(a.size()){
            y=y*10+a.back();
            a.pop_back();
        }
    }
    cout<<x+y<<endl;
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}