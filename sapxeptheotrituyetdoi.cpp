
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct data{
    int pos = 0;
    int val = 0;
    int abs = 0;
};

bool cmp(data a,data b){
    if(a.abs == b.abs) return a.pos < b.pos;
    return a.abs < b.abs;
}

void solve(){
    int n,x;
    cin>>n>>x;
    vector<data>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].val;
        a[i].pos = i;
        a[i].abs = abs(x-a[i].val);
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<a[i].val<<' ';
    }
    cout<<endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}