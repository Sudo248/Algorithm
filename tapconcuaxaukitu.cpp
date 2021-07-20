#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int n;
string S;
vector<string>res;

void process(string s){
    string tmp = "";
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            tmp += S[i];
        }
    }
    if(tmp!="") res.push_back(tmp);
}


void Try(string s){
    if(s.length() == n){
        process(s);
    }
    else{
        Try(s+"0");
        Try(s+"1");
    }
}
void solve(){

    cin >> n;
    cin >> S;
    res.clear();
    Try("");
    sort(res.begin(), res.end());
    for(string &s:res){
        cout << s << ' ';
    }
    cout <<endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}