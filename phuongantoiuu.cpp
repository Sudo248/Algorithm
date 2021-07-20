#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
struct data{
    int value, weight;
};
string XOPT;
vector<data>a;
int n,w,FOPT = 0;

void process(string s){
    int value = 0, weight = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == '1'){
            value +=  a[i].value;
            weight += a[i].weight;
        }
    }
    if(value > FOPT && weight <= w){
        FOPT = value;
        XOPT = s;
    }
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
    cin >> n >> w;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i].value;
    }
    for(int i=0;i<n;i++){
        cin >> a[i].weight;
    }
    Try("");
    cout << FOPT << endl;
    for(char &c:XOPT) cout << c << ' ';



}


int main(){
    faster
    solve();

    return 0;

}