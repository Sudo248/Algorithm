#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    string s;
    cin >> s;
    stack<char> st;
    st.push('+');
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            if(i==0) continue;
            st.push(s[i-1]);
        }
        else if(s[i] == ')'){
            if(st.size()) st.pop();
        }else{
            if(s[i] == '+' | s[i] == '-'){
                if(st.top() == '+') continue;
                else{
                    if(s[i] == '-') s[i] = '+';
                    else s[i] = '-';
                }
            }
        }
    }
    for(char c:s){
        if(c!='(' && c!=')') cout << c;
    }
    cout << endl;

}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}