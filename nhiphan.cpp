
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int n;
void Try(string s){
    if(s.length()==n) cout<<s<<' ';
    else{
        Try(s+"A");
        Try(s+"B");
    }
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        Try("");
        cout<<endl;
    }



    return 0;
}