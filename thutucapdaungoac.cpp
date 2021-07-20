#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    string s;
    getline(cin,s);
    int count = 1;
    stack<int>st;
    for(char &c:s){
        if(c == '('){
            cout << count << ' ';
            st.push(count++);
        }
        else if(c == ')'){
            cout << st.top() << ' ';
            st.pop();
        }
    }
    cout << endl;


}


int main(){
    faster
    int t;
    cin >> t;
    cin.ignore();
    while(t--) solve();

    return 0;

}