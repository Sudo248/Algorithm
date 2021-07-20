
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,Max=INT_MIN;
    string s;
    cin>>n>>s;
    int dd[300]={0};
    for(char i:s){
        dd[i]++;
        Max = Max < dd[i] ? dd[i] : Max;
    }
    if((Max - 1)*(n - 1) > (s.length()-Max) ) cout<<-1<<endl;
    else cout<<1<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}