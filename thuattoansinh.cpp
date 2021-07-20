
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<string>res;
int m, n;

void Try(string s){
    if(s.length() == m) res.push_back(s);
    else{
        Try(s+"0");
        Try(s+"1");
    }
}

void solve(){
    int n;
    cin >> n;
    m = n/2;
    Try("");
    int x = res.size();
    for(int i=0;i<x; i++){
        if(n%2==1){
            string S = res[i] + "1";
            int e = res[i].length();
            res[i] += "0";
            for(int j = e-1; j>=0;j--){
                res[i] += res[i][j];
                S += res[i][j];
            }
            res.push_back(S);
        }
        else{
            int e = res[i].length();
            for(int j = e-1; j>=0;j--){
                res[i] += res[i][j];
            }
        }
    }
    if(n%2==1) sort(res.begin(), res.end());
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].length();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    faster
    solve();

    return 0;
}