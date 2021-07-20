
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

ll process(ll a,ll b,char c){
    if(c == '+') return a+b;
    if(c == '-') return a-b;
    if(c == '*') return a*b;
    if(c == '/') return a/b;
    if(c == '%') return a%b;
    if(c == '^'){
        int res = 1;
        for(int i=0;i<b;i++) res*=a;
        return res;
    }
    return 0;
}

bool isNumber(char c){
    return c>='0' && c<='9';
}

void solve(){
    string s;
    cin>>s;
    stack<ll>st;
    for(int i=s.length()-1;i>=0;i--){
        if(isNumber(s[i])){
            st.push(s[i]-'0');
        }
        else{
            ll a,b;
            a = st.top(); st.pop();
            b = st.top(); st.pop();
            st.push(process(a,b,s[i]));
        }
    }
    cout<<st.top()<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}