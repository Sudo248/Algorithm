#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    string s;
    getline(cin,s);
    stack<int> st;
    st.push(-1);
    int res = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            st.push(i);
        }else{
            st.pop();
            if(st.size()){
                res = max(res, i-st.top());
            }
            else{
                st.push(i);
            }
        }
    }
    cout << res << endl;


}


int main(){
    faster
    int t;
    cin >> t;
    cin.ignore();
    while(t--) solve();

    return 0;

}