#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
 
void solve(){
 
    int n;
    cin  >> n;
    bool checked;
    vector<int>a(n);
    for(int &i:a) cin >> i;
    for(int i=0;i<n;i++){
        checked = false;
        for(int j=i+1;j<n;j++){
            if(a[j] > a[i]){
                checked = true;
                cout << a[j] << ' ';
                break;
            }
        }
        if(!checked) cout << "-1 ";
    }
    cout << endl;
 
}
 
 
int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();
 
    return 0;
 
}