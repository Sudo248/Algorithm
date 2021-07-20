
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    string s;
    getline(cin,s);
    int dd[300]={0};
    int n = s.length();
    if(n%2==0) n = n/2;
    else n = n/2+1;
    for(char &i:s){
        dd[i]++;
    }
    for(int i='a';i<'z';i++){
        if(dd[i] > n){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<1<<endl;
}

int main(){
    faster
    int t;
    cin>>t;
    cin.ignore();
    while(t--) solve();


    return 0;
}