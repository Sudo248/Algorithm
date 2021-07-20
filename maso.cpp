#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int n;
vector<string>a,b;
 
vector<bool>checked(300,false);
 
void TryAlpha(string s){
    for(char c = 'A'; c < 'A'+n;c++){
        if(!checked[c]){
            s+=char(c);
            checked[c] = true;
            if(s.length() == n) a.push_back(s);
            else{
                TryAlpha(s);
 
            }
            s.pop_back();
            checked[c] = false;
        }
    }
}
 
void TryNumber(string s){
    for(char c = '1'; c < '1'+n;c++){
        if(!checked[c]){
            s+=char(c);
            if(s.length() == n) b.push_back(s);
            else{
                TryNumber(s);
 
            }
            s.pop_back();
        }
    }
}
 
void solve(){
 
    cin >> n;
    a.clear();b.clear();
    checked.resize(300,false);
    TryAlpha("");
    TryNumber("");
 
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            cout << a[i] << b[j] << endl;
        }
    }
 
 
}
 
 
int main(){
    faster
    solve();
 
    return 0;
 
}
