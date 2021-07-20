
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int x = n/7, num4 = 0, num7 = 0;
    for(int i=0;i<=x;i++){
        if((n-i*7)%4==0){
            num7 = i;
            num4 = (n-i*7)/4;
        }
    }
    if(num4 == 0 && num7 == 0){
        cout << -1 << endl;
    }
    else{
        for(int i=0;i<num4;i++) cout << 4;
        for(int i=0;i<num7;i++) cout << 7;
        cout << endl;
    }
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}