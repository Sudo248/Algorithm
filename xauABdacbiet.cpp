
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<string>res;
int n,k;

void process(string s){
    int dem = 0,d = 0;
    for(int i=0;i<s.length(); i++){
        if(s[i] == 'B') d = 0;
        else d ++;
        if(d >= k) dem++;
        if(dem > 1) return;
    }
    if(dem == 1){
        res.push_back(s);
    }

}

void Try(string s){
    if(s.length() == n) process(s);
    else{
        Try(s+"A");
        Try(s+"B");
    }
}

void solve(){
    
    cin >> n >> k;
    Try("");
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }

}

int main(){
    faster

    solve();

    return 0;
}