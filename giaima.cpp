
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

bool enCode(char a,char b){
    int res = (a-'0')*10+(b-'0');
    return res <= 26; 
}

void solve(){
    string s;
    cin>>s;
    if(s[0]=='0') {
        cout<<0<<endl;
        return;
    }
    int len = s.length();
    vector<int>res(len+1,0);
    res[0]=res[1]=1;
    for(int i=2;i<=len;i++){
        if(s[i-1]>'0') res[i]=res[i-1];
        if(s[i-2]=='1'){
            res[i] = res[i] + res[i-2]; 
        }
        else{
            if(s[i-2]=='2' &&s[i-1]<='6'){
                res[i] = res[i] + res[i-2]; 
            }
        }
    }
    cout<<res.back()<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}