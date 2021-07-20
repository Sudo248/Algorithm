#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
// vector<string>res;
bool dd = true;
int n;
int a[15][15];
void Try(int i,int j,string way){
    if(i == n-1 && j == n-1 && a[i][j] == 1){
        cout<<way<<' ';
        dd = false;
        return;
    }
    if(a[i+1][j]){
        Try(i+1,j,way+"D");
    }
    if(a[i][j+1]){
        Try(i,j+1,way+"R");
    }

}

void solve(){
    cin>>n;
    dd = true;
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            a[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    if(a[0][0] == 0 || a[n-1][n-1] == 0){
        dd = false;
        cout<<-1;
    }
    else Try(0,0,"");
    if(dd) cout<<-1;
    cout<<endl;
    
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}