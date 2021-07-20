#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    string s;
    stack<char>st;
    cin >> s;
    int res = 0, deleted = 0;
    for(char c:s){
        if(st.empty()) {
            st.push(c);
        }
        else if(st.top() == '[' && c == ']'){
            st.pop();
            deleted += 2;
        }
        else if(st.top() == ']' && c == '['){
            res += st.size() + deleted;
            st.pop();
        }
        else st.push(c);

        if(st.empty()) deleted = 0;

    }
    cout << res << endl;

}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}