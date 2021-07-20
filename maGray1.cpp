
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<string>a;

void Gray(int dem){
    for(int i = a.size() - 1; i >= 0; i--){
        a.push_back(a[i]);
    }
    for(int i = 0; i < dem; i++){
        a[i] = "0" + a[i];
        a[i+dem] ="1" + a[i+dem];
    }
}

void solve(){
    int n,dem = 2;
    cin >> n;
    a.clear();
    a.push_back("0");
    a.push_back("1");
    
    while(--n){
        Gray(dem);
        dem *= 2;
    }
    for(int i = 0; i < a.size(); i++){
        cout<<a[i]<<' ';
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