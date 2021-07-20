
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<int>a;
int n,k;

void init(int k){
    for(int i=0;i<k;i++)a[i]=0;
}

void Try(int i){
    for(int j=a[i-1]+1;j<=n-k+i;j++){
        a[i]=j;
        if(i==k) {
            vector<int>res(n+1,1);
            for(int e=1;e<=k;e++){
                res[a[e]]=0;
            }
            for(int e=1;e<=n;e++) cout<<res[e];
            cout<<endl;
        }
        else{
            Try(i+1);
        }
    }
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        k=n-k;
        a.resize(k+1);
        a[0]=0;
        Try(1);
        // cout<<endl;
    }

    return 0;
}