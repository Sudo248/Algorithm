#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int priority(char c){
    if(c == '(') return 0;
    if(c == '+' | c == '-') return 1;
    if(c == '*' | c == '/') return 2;
    return 3;
}

int to_int(string s){
    int res = 0;
    for(char &c:s) res = res *10 + (c - '0');
    return res;
}

ll cal(ll a, ll b, string c){
    if(c == "+") return a+b;
    if(c == "-") return a-b;
    if(c == "*") return a*b;
    if(c == "/") return a/b;
    return 0;
}

vector<string> convert(string s){
    vector<string> res;
    stack<char> st;
    string tmp = "";

    for(char &c : s){
        if(c == '(') st.push(c);
        else if(c == ')'){

            if(tmp != ""){
                res.push_back(tmp);
                tmp = "";
            }

            while(st.top() != '('){
                res.push_back(string(1, st.top()));
                st.pop();
            }
            st.pop();

        }else if(isdigit(c)){
            tmp += c;
        }else{
            if(tmp != ""){
                res.push_back(tmp);
                tmp = "";
            }
            while(st.size() && priority(c) <= priority(st.top())){
                res.push_back(string(1,st.top()));
                st.pop();
            }
            st.push(c);
        }
    }
    if(tmp != "") res.push_back(tmp);
    while(st.size()){
        res.push_back(string(1,st.top()));
        st.pop();
    }

    return res;
}

ll caculator(vector<string> vt){
    stack<ll>st;
    for(string &s : vt){
        if(isdigit(s[0])){
            st.push(to_int(s));
        }
        else{
            ll a = st.top(); st.pop();
            ll b = st.top(); st.pop();
            st.push(cal(b,a,s));
        }
    }
    return st.top();
}

void solve(){

    string s;
    cin >> s;
    // vector<string> hauto = convert(s);
    cout << caculator(convert(s)) << endl;
    // for(string &i : hauto) cout << i ;



}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}