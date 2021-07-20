#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int n,x;
vector<int>a,b;
vector<vector<int> >res;

void Try(int i, int s){
    for(int j=i;j<n;j++){
        if(s+a[j] <= x){
            b.push_back(a[j]);
            if(s+a[j] == x) {
                res.push_back(b);
            }
            else Try(j,s+a[j]);
            b.pop_back();
        }
    }
}

void solve(){

    cin >> n >> x;
    a.resize(n);
    res.clear();
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    if(a[0] > x){
        cout << "-1\n";
        return;
    }
    Try(0,0);
    if(res.empty()){
        cout << -1 << endl;
    }
    else{
        cout << res.size() << ' ';
        for(int i=0;i<res.size();i++){
            cout << "{";
            for(int j=0;j<res[i].size()-1;j++)
                cout << res[i][j] << ' ';
            cout << res[i].back() << "} ";
        }
        cout << endl;
    }


}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}