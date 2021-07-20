
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int a[11][11], dd[11];
vector<vector<int> > ans;
vector<int>res;
int n,k;

void Try(int i, int s){
    
    if(s == k && res.size() == n){
        ans.push_back(res);
        return;
    }

    if(i >= n) return;

    for(int j = 0; j < n; j++){
        if(!dd[j] && (s+a[i][j] <= k)){
            res.push_back(j+1);
            dd[j] = true;
            Try(i+1,s+a[i][j]);
            res.pop_back();
            dd[j] = false;
        }
    }
    
}

void solve(){

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
        dd[i] = 0;
    }
    ans.clear();
    res.clear();

    Try(0,0);

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

}

int main(){
    faster
    solve();

    return 0;
}