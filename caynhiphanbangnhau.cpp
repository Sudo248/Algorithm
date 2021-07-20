#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n,m;
    cin >> n;
    vector<string>tree1, tree2;
    string a,b,c;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        tree1.push_back(a+" "+b+" "+c);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        tree2.push_back(a+" "+b+" "+c);
    }
    if(n == m){
        sort(tree1.begin(), tree1.end());
        sort(tree2.begin(), tree2.end());
        for(int i=0;i<n;i++){
            if(tree1[i] != tree2[i]){
                cout << "0\n";
                return;
            }
        }

        cout << "1\n";
    }
    else cout << "0\n";
    


}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}