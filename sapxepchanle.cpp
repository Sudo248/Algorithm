#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    vector<int>le,chan;
    for(int i=1;i<=n;i++) {
        int x;
        cin >> x;
        if(i%2){
            le.push_back(x);
        }
        else chan.push_back(x);
    }
    sort(le.begin(),le.end());
    sort(chan.rbegin(),chan.rend());
    int pos1=0,pos2=0;
    for(int i=1;i<=n;i++) {
        if(i%2){
            cout << le[pos1++] << ' ';
        }
        else cout << chan[pos2++] << ' ';
    }


}


int main(){
    faster
    solve();

    return 0;

}