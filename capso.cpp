#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

bool cmp(pair<int, int> a, pair<int, int >b){
    if(a.first == b.second) return a.second < b.second;
    return a.first < b.first;
}

void solve(){

    int n, res = 0;
    cin >> n;
    vector<pair<int, int> > vt(n);
    vector<int>a(n,0);
    for(int i=0;i<n;i++){
        cin >> vt[i].first >> vt[i].second;
    }
    sort(vt.begin(), vt.end(), cmp);
    for(int i=0;i<n;i++){
        a[i] = 1;
        for(int j=0;j<i;j++){
            if(vt[j].second < vt[i].first){
                a[i] = max(a[i], a[j]+1);
            }
        }
        res = max(res, a[i]);
    }

    cout << res << endl; 
    

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}