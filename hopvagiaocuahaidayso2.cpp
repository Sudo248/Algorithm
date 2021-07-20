#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    set<int>Union;
    for(int i=0;i<n;i++){
        cin>>a[i];
        Union.insert(a[i]);
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        Union.insert(b[i]);
    }
    for(int i:Union){
        cout<<i<<" ";
    }
    cout<<"\n";
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n>m){
        for(int i=0;i<m;i++){
            if(binary_search(a.begin(),a.end(),b[i])){
                cout<<b[i]<<" ";
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            if(binary_search(b.begin(),b.end(),a[i])){
                cout<<a[i]<<" ";
            }
        }
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