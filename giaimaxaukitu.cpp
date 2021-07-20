#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

string mulString(int time, string s){
    string res = "";
    for(int i=0;i<time;i++) res += s;
    return res;
}

int to_int(string s){
    if(s == "") return 1;
    int res = 0;
    for(char &c:s) res = res * 10  + (c-'0');
    return res;
}

void solve(){
     
    string s, digit="", tmp = "";
    cin >> s;
    
    stack<int> times;
    stack<string> stk;

    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(isdigit(c)) digit += c;
        else if(c == '['){
            times.push(to_int(digit));
            if(tmp != ""){
                stk.push(tmp);
                tmp = "";
            }
            digit = "";

        }else if( c == ']'){
            string str;
            if(stk.size()){
                str = stk.top();
                stk.pop();
            }   
            
            str += mulString(times.top(), tmp);
            times.pop();
            tmp = str;

        }else{
            tmp += c;
        }
    }

    cout << tmp << endl;
    

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}