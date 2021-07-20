#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

string change(string s){
    string res = "";
    stack<int>st;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            st.push(i);
        }
        else if(s[i] == ')'){
            if(st.size()) {
                int be = st.top();st.pop();
                if(be == 0) continue;
                char dau = s[be-1];                
                for(int j = be;j<=i;j++){
                    if(dau == '-'){
                        if(s[j] == '-') s[j] = '+';
                        else if(s[j] == '+') s[j] = '-';
                    }   
                }
            }
            
        }
    }

    for(int i=0;i<s.length();i++){
        if(s[i] == '(' || s[i] == ')') continue;
        res+=s[i];
    }
    return res;
}

void solve(){

    string s1,s2;
    cin >> s1 >> s2;    
    s1 = change(s1);
    s2 = change(s2);
    // cout << s1 << endl << s2 << endl;
    if(s1==s2) cout << "YES\n";
    else cout << "NO\n";

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}