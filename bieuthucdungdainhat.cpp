#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    string s;
    int res = 0;
    cin >> s;
    stack<char>st;
    for(char &c:s){
        if(st.empty()){
            st.push(c);
        }
        else if(st.top() == '(' && c == ')'){
            st.pop();
            res +=2;
        }
        else st.push(c);
    }
    cout << res << endl;

    


}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}