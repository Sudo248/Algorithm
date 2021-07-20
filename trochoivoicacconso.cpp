#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        a[i] = i+1;
    }
    do{
        bool dd = true;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]+1 | a[i] == a[i-1]-1) {
                dd = false;
                break;
            }
        }
        if(dd){
            for(int &i:a) cout << i;
            cout << endl;
        }

    }while(next_permutation(a.begin(),a.end()));

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}