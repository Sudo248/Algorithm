
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct data{
    int val,ts,pos;
    data(){
        val=ts=0;
    }
};

bool cmp(data a,data b){
    if(a.ts == b.ts) return a.val < b.val;
    return a.ts > b.ts;
}

void solve(){
    int n;
    cin>>n;
    vector<data>a(n);
    map<int,int>ts;
    for(int i=0;i<n;i++){
        cin>>a[i].val;
        ts[a[i].val]++;
    }
    for(int i=0;i<n;i++){
        a[i].ts = ts[a[i].val];
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