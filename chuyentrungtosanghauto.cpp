#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int priority(char c){
    if(c == '(') return 1;
    if(c == '+' | c == '-') return 2;
    if(c == '*' | c == '/') return 3;
    if(c == '^') return 4;
    return 0;
}

void solve(){

    string s;
    cin >> s;
    stack<char>st;
    for(char &c:s){
        if(isalpha(c)){
            cout << c;
        }
        else if(c == '(') st.push(c);
        else if(c == ')'){
            while (st.top() != '('){
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(st.size() && priority(c) <= priority(st.top())){
                cout << st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(st.size()){
        cout << st.top();
        st.pop();
    }
    cout << endl;

}

int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();
    return 0;

}