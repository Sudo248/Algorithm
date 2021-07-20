
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

string GrayToBinary(string G){
    string B = "";
    B = B + G[0];
    for(int i = 1; i < G.length(); i++){
        if(G[i] == B[i-1]) B += "0";
        else B += "1";
    }
    return B;
}

void solve(){
    string s;
    cin >> s;
    cout << GrayToBinary(s) << endl;
    
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}