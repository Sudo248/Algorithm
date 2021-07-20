
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    string s;
    set<int>a;
    for(int i=0;i<n;i++){
        cin>>s;
        for(char &i:s){
            a.insert(i-'0');
        }
    }
    for(int i:a) cout<<i<<" ";
    cout<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}