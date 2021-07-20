
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin>>s;
    stack<char>st;
    int len = s.length();
    for(int i=0;i<len;i++){
        if(s[i] == '(' | st.empty()) st.push(s[i]);
        else if(s[i] == ')'){
            if(st.size() && st.top() == '(') st.pop();
            else st.push(s[i]);
        }
    }
    int n = st.size(),dem1 = 0,dem2;
    while (st.size())
    {
        if(st.top() == '(') dem1++;
        st.pop();
    }
    dem2 = n - dem1;
    cout<<dem1/2 + dem2/2 + dem1%2 + dem2%2<<endl;
    

}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}