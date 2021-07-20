
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<int>a;
vector<string>check;
bool dd = true;
int n,k;

void process(string s){
    if(!binary_search(check.begin(),check.end(),s)){
        int sum = 0;
        vector<int>res;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                sum += a[i];
                res.push_back(a[i]);
            }
        }
        if(sum == k){
            dd = false;
            cout<<"[";
            for(int i=0;i<res.size()-1;i++){
                cout<<res[i]<<' ';
            }
            cout<<res.back()<<"] ";
        }
    }
    check.push_back(s);
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
    cin>>n>>k;
    check.clear();
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    dd = true;
    Try("");
    if(dd){
        cout<<-1;
    }
    cout<<endl;
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}