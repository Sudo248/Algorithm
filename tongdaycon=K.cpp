
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<vector<int> > res;
vector<int>a;
int n, k;

void Try(string s){
    if(s.length() == n){
        int sum = 0;
        vector<int>b;
        for(int i=0;i<n;i++){
            if(s[i] == '1') {
                sum += a[i];
                b.push_back(a[i]);
            }
        }
        if(sum == k){
            res.push_back(b);
        }
    }
    else{
        Try(s+"0");
        Try(s+"1");
    }
}

void solve(){
    
    cin >> n >> k;
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
    Try("");
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    cout << res.size();
}

int main(){
    faster

    solve();

    return 0;
}