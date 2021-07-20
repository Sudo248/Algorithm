#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define MAX int(1e4+5)
using namespace std;
typedef long long ll;

vector<int>res;

int to_Int(string s){
    int x = 0;
    for(char &c:s){
        x = x * 10 +(c - '0');
    }
    return x;
}

int tachHeSo(string s){
    string tmp = "";
    if(s[0] == 'x') return 1;
    for(char &c:s){
        if(c == '*'){
            return to_Int(tmp);
        }
        tmp += c;
    }
    return 0;
}

int tachSoMu(string s){
    string tmp = "";
    for(int i=s.length()-1;i>=0;i--){
        if(s[i] == '^'){
            return to_Int(tmp);
        }
        tmp = s[i] + tmp;
    }
    return 0;
}

void process(vector<string>vt){
    for(int i=1;i<vt.size();i++){
        if(vt[i] != "+" && vt[i] != "-"){
            res[tachSoMu(vt[i])] += tachHeSo(vt[i]);
        }
    }
}

void solve(){

    string s1,s2, tmp = "";
    res.assign(MAX,0);
    getline(cin,s1);
    getline(cin,s2);
    vector<string>vt1,vt2;
    vt1.push_back("+");
    vt2.push_back("+");
    stringstream ss1(s1), ss2(s2);
    while (ss1 >> s1) vt1.push_back(s1);
    while (ss2 >> s2) vt2.push_back(s2);
    
    process(vt1);
    process(vt2);

    string Res = "";
    bool isFirst = true;

    for(int i=MAX;i>=0;i--){
        if(res[i] != 0){
            if(isFirst){
                cout << to_string(res[i]) + "*x^" + to_string(i);
                isFirst = false;
            }
            else{
                cout << " + " + to_string(res[i]) + "*x^" + to_string(i);
            }
        }  
    }
    cout << endl;
}

int main(){
    faster
    int t;
    cin >> t;
    cin.ignore();
    while(t--) solve();

    return 0;

}