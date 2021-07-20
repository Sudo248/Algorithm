
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int isCal(char c){
    if(c == '+') return 1;
    if(c == '-') return 2;
    if(c == '*') return 3;
    if(c == '/') return 4;
    if(c == '%') return 5;
    if(c == '^') return 6;
    return 0;
}

void solve(){
    string s,a,b;
    cin>>s;
    stack<string>st;
    for(int i=0;i<s.length();i++){
        switch(isCal(s[i])){
            case 0:
                st.push(string(1,s[i]));
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                a = st.top();st.pop();
                b = st.top();st.pop();
                st.push(s[i]+b+a);
                break;
        }
    }
    while(st.size()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}