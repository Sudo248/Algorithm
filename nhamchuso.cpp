
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int stringToInt(string s){
    int res=0;
    for(char i:s){
        res = res*10+(i-'0');
    }
    return res;
}

int sumMin(string a,string b){
    for(char &i:a) if(i=='6') i='5';
    for(char &i:b) if(i=='6') i='5';
    return stringToInt(a)+stringToInt(b);
}

int sumMax(string a,string b){
    for(char &i:a) if(i=='5') i='6';
    for(char &i:b) if(i=='5') i='6';
    return stringToInt(a)+stringToInt(b);
}

void solve(){
    string a,b;
    cin>>a>>b;
    cout<<sumMin(a,b)<<' '<<sumMax(a,b);
}

int main(){
    faster
    solve();


    return 0;
}