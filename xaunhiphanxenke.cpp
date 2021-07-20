#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        if(i%2){
            cout <<"1 ";
        }
        else cout << "0 ";
    }
    cout << endl;
    for(int i=0;i<n;i++){
        if(i%2){
            cout <<"0 ";
        }
        else cout << "1 ";
    }

}


int main(){
    faster
    solve();

    return 0;

}