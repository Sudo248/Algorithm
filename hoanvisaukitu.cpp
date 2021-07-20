
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<int>a;
vector<bool>check;
string res;
int n;

void Try(int i){
    for(int j=1;j<=n;j++){
        if(!check[j]){
            a.push_back(j);
            check[j]=true;
            if(a.size()==n){
                for(int e=0;e<n;e++){
                    cout<<res[a[e]-1];
                }
                cout<<" ";
            }
            else{
                Try(i+1);
            }
            a.pop_back();
            check[j]=false;
        }
    }
}

void solve(){
    a.clear();
    check.resize(15,false);
    cin>>res;
    n = res.length();
    Try(1);
    cout<<endl;
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}