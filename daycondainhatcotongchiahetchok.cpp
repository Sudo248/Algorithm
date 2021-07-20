#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct data{
    int sum, count;
};

void solve(){

    int n,k,res=0;
    cin >> n >> k;
    vector<int>a(n);
    vector<data>b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        b[i].sum = a[i];
        b[i].count = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j] < a[i]){
                b[i].sum = a[i]+b[j].sum;
                b[i].count = b[j].count+1;
                if(b[i].sum % k == 0){
                    res=max(res,b[i].count);
                }
                
            }
        }
    }
    cout <<res<<endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}