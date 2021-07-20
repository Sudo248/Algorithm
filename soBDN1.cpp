
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

ll power(int a,int b){
    if(b == 0) return 1;
    if(b == 1) return a;

    ll res = power(a,b/2);
    if(b%2) return a*res*res;
    return res*res;

}

ll cal(int n){
    ll res = 0;
    for(int i=0;i<n;i++){
            res+=power(2,i);
    }
    return res;
}


void solve(){
    string s;
    cin>>s;
    ll res = 0,n;
    n = s.length();
   
    if(s[0] > '1'){
        cout<<cal(n)<<endl;
    }
    else{
         for(int i=0;i<n;i++){
            if(s[i]>='2'){
                for(int j=i;j<n;j++)
                    s[j] = '1';
                break;
            }
        }
        ll res = cal(n-1) + 1;
        for(int i=1;i<n;i++){
            if(s[i] == '1'){
                res += cal(n-i-1)+1;
            }
        }
        cout<<res<<endl;
        
    }
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}