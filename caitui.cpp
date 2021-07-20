
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct data{
    int value = 0;
    int weight = 0;
};

void solve(){

    int n,V;
    cin>>n>>V;
    vector<data>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i].weight;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i].value;
    }
    int dd[1001][1001]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=V;j++){
            if(j>=a[i].weight) 
                dd[i][j] = max(dd[i-1][j],dd[i-1][j-a[i].weight]+a[i].value);
            else 
                dd[i][j] = dd[i-1][j]; 
        }
    }
    cout<<dd[n][V]<<endl;

    
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}