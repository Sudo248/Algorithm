
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<int>res;
vector<int>a;
int n,x;
bool dd;

void print(){
    dd = false;
    cout << '[';
    for(int i=0;i<res.size()-1;i++) cout <<res[i]<<' ';
    cout << res.back() << ']';
}

void Try(int i){
    for(int j = i; j < n; j++){
        if(x >= a[j]){
            x-=a[j];
            res.push_back(a[j]);
            if(x == 0 ){
                print();
            }
            else Try(j);
            x+=a[j];
            res.pop_back();
        }
    }
}

void solve(){

    cin >> n >> x;
    a.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    dd = true;
    Try(0);
    if(dd) cout << -1;
    cout << endl;

}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}