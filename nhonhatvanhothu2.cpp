
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,x;
    cin>>n;
    set<int>a;
    for(int i=0;i<n;i++){
        cin>>x;
        a.insert(x);
    }
    if(a.size()==1) cout<<-1<<endl;
    else{
        int dd=0;
        for(int i:a){
            cout<<i<<' ';
            if(++dd == 2) break;
        }
        cout<<endl;
    }

}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}