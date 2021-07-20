#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    queue<string>q;
    q.push("H");
    while(true){
        string tmp = q.front();q.pop();
        if(tmp.length() == n){
            while(tmp.length() == n){
                if(tmp.back()=='A') 
                    cout << tmp << '\n';
                if(q.empty()) return;
                tmp = q.front();q.pop();
            }
            return;
        }
        else if(tmp.back() == 'H'){
            q.push(tmp+"A");
        }
        else{
            q.push(tmp+"A");
            q.push(tmp+"H");
        }
    }

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}