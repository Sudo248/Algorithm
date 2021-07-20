
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void show(stack<int>st){
    if(!st.size()){
        cout<<"empty\n";
        return;
    }
    string s="";
    while(st.size()){
        s = to_string(st.top()) + " " +s;
        st.pop();
    }
    cout<<s<<endl;
}

void solve(){
    string s;
    stack<int>st;
    while(cin>>s){
        if(s=="-1") break;
        if(s[0] == 'p'){
            if(s[1]=='u'){
                int x;
                cin>>x;
                st.push(x);
            }
            else if(st.size()){
                st.pop();
            }
        }
        else show(st);
    }
}

int main(){
    faster

    solve();

    return 0;
}