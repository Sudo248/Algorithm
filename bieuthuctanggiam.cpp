#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    string s;
    cin >> s;
    stack<int>st;
    for(int i=0;i<=s.length();i++){
        st.push(i+1);
        if(s[i] == 'I'){
            while(st.size()){
                cout << st.top();
                st.pop();
            }
        }
    }
    while (st.size())
    {
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