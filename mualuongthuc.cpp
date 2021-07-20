
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,s,m,res = 0,day = 0,current = 0;
    cin>>n>>s>>m;
    m = s*m;
    for(int i=1;i<=s;i++){
        day++;
        if(day == 7) day = 0; 
        else {
            res++;
            current += n;
            if(current >= m){
                break;
            }
        }
    }
    if(current < m) res = -1;
    cout<<res<<endl;

}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}