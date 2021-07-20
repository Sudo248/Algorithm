#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<pair<int,int> > mau;
string S;
set<string>res;
int n;
void Try(string s){
    if(s.length() == n){
        string tmp = S;
        bool check = false;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                tmp[mau[i].first] = '$';
                tmp[mau[i].second] = '$';
                check = true;
            }
        }
        string r = "";
        for(char &c:tmp){
            if(c != '$') r += c;
        }
        if(check) res.insert(r);
    }
    else{
        Try(s+"0");
        Try(s+"1");
    }
}

void solve(){

    cin >> S;
    stack<int> st;
    mau.clear();
    res.clear();
    for(int i = 0; i < S.length();i++){
        if(S[i] == '(') st.push(i);
        else if(S[i] == ')'){
            mau.push_back({st.top(), i});
            st.pop();
        }
    }
    n = mau.size();
    Try("");
    for(string s: res){
        cout << s << endl;
    }
}
int main(){
    faster
    solve();
    return 0;
}