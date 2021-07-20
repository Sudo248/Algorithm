#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef unsigned long long ull;
vector<string>Catalan;

void standardized(string &a,string &b){
    if(a.length()<b.length()){
        while(a.length()<b.length()){
            a='0'+a;
        }
 
    }
    else{
        while(a.length()>b.length()){
            b='0'+b;
        }
    }
}
string sum(string a,string b){
    string s="";
    standardized(a,b);
    int nho=0;
    for(int i=a.length()-1;i>=0;i--){
        nho=nho+(a[i]-'0')+(b[i]-'0');
        s=(char)((nho%10)+'0')+s;
        nho=nho/10;
    }
    if(nho>0){
       s=(char)(nho+'0')+s;
    }
    return s;
}

string multilpy(string a, string b){
    string t="";
    string T="";
    int nho=0;
    int x=0;
    for(int i=b.length()-1;i>=0;i--){
        for(int j=a.length()-1;j>=0;j--){
            nho=nho+(b[i]-'0')*(a[j]-'0');
            t=(char)(nho%10+'0')+t;
            nho=nho/10;
        }
        if(nho>0){
            t=(char)(nho+'0')+t;
            nho=0;
        }
        t.insert(t.length(),x,'0');
        T=sum(T,t);
        x++;
        t.clear();
    }
    while(T.length()!=1&&T[0]=='0'){
        T.erase(0,1);
    }
    return T;
}

void prepare(){
    Catalan.push_back("1");
    Catalan.push_back("1");
    Catalan.push_back("2");
    for(int n=3;n<=100;n++){
        string tmp = "";
        int x = n/2;
        for(int i=0;i<x;i++){
            // tmp += Catalan[i]*Catalan[n-i-1];
            string T = multilpy(Catalan[i], Catalan[n-i-1]);
            tmp = sum(tmp, T);
        }
        // tmp *= 2;
        tmp = multilpy("2",tmp);
        if(n%2==1){
            // tmp += Catalan[x]*Catalan[x];
            string T = multilpy(Catalan[x], Catalan[x]);
            tmp = sum(tmp, T);
        }
        Catalan.push_back(tmp);
    }
}

void solve(){

    int n;
    cin >> n;
    
    cout << Catalan[n] << endl;

}


int main(){
    faster
    prepare();
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}