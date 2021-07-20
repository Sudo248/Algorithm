#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    string s;
    cin >> s;
    stack<string>st;
    for(char c:s){
        if(c == '+' | c == '-' | c == '*' | c == '/' | c == '^'){
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string S = "("+s2+c+s1+")";
            st.push(S);
        }else st.push(string(1,c));
    }

    cout << st.top() << endl;

}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}