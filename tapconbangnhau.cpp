
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int sum,n;
vector<int>a;

bool dd = false;
void Try(int j,int subSum){
    for(int i=j;i<n;i++){
        subSum += a[i];
        if(dd || subSum > n/2) return;
        if(subSum == n/2){
            dd = true;
            return;
        }
        else Try(i,subSum);
        subSum -= a[i];
    }
}

void solve(){
    cin>>n;
    a.resize(n);
    sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum % 2 == 1){
        cout<<"NO\n";
        return;
    }
    sort(a.begin(),a.end());
    Try(0,0);
    if(dd){
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--) solve();


    return 0;
}