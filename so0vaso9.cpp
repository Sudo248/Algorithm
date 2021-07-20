#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

string BDN(int n){
    string res;
    queue<string>q;
    q.push("9");
    while(q.size()){
        res = q.front();q.pop();
        ll tmp = 0;
        for(int i=0;i<res.length();i++){
            tmp = tmp * 10 + (res[i]-'0');
            tmp%=n;
        }
        if(tmp == 0){
            return res;
        }
        q.push(res+"0");
        q.push(res+"9");
    }
    return "";
}

void solve(){
    int n;
    cin>>n;
    cout<<BDN(n)<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}