
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;


void solve(){
    int n;
    cin>>n;
    string s;
    stack<int>st;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s == "PUSH"){
            int x;
            cin>>x;
            st.push(x);
        }
        else if(s == "POP"){
            if(st.size()) st.pop();
        }
        else {
            if(st.size()){
                cout<<st.top()<<endl;
            }
            else cout<<"NONE\n";
        }
    }
}

int main(){
    faster
    solve();

    return 0;
}