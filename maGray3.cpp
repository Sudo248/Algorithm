
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

string BinaryToGray(string B){
    string G = "";
    G = G + B[0];
    for(int i = 1; i < B.length(); i++){
        if(B[i] == B[i-1]) G += "0";
        else G += "1";
    }
    return G;
}

void solve(){
    string s;
    cin >> s;
    cout << BinaryToGray(s) << endl;

}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}