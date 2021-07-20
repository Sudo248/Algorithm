
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    string s;
    getline(cin,s);
    bool check = true;
    stack<char>st;
    for(char i:s){
        if(i == ')'){
            check = true;
            while(st.size() && st.top() != '('){
                char top = st.top();st.pop();
                if(top == '+' | top == '-' | top == '*' | top == '/') 
                    check = false;
            }
            st.pop();
            if(check) break;
        }
        else st.push(i);
    }
    if(check) cout<<"Yes\n";
    else cout<<"No\n";
}

int main(){
    faster

    int t;
    cin>>t;
    cin.ignore();
    while(t--) solve();

    return 0;
}