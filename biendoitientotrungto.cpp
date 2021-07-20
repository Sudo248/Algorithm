#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

bool isOperater(char c){
    return c == '+' | c == '-' | c == '*' | c == '/' | c == '^';
}

void solve(){

    string s;
    cin >> s;
    stack<string>st;

    for(int i=s.length()-1;i>=0;i--){
        if(isOperater(s[i])){
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            st.push("("+a+s[i]+b+")");
        }
        else st.push(string(1,s[i]));
    }
    cout << st.top() << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}