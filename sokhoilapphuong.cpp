#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<ll>mau;
string S;
int n;
ll res;

void init(){
    for(ll i=1;i<=(ll)(1e6);i++){
        mau.push_back(i*i*i);
    }
}

void process(string s){
    ll tmp = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            tmp = tmp*10+(S[i] - '0');
        }
    }
    if(binary_search(mau.begin(), mau.end(), tmp)){
        res = max(res,tmp);
    }
}

void Try(string s){
    if(s.length() == n){
        process(s);
    }
    else{
        Try(s+"1");
        Try(s+"0");
    }
}

void solve(){
    res = -1;
    cin >> S;
    n = S.length();
    Try("");
    cout << res << endl;
}


int main(){
    faster
    init();
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}