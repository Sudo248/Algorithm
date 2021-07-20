#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
 
struct data{
    int value, count;
};
 
void solve(){
 
    int n;
    cin >> n;
    queue<data>q;
    q.push({n,0});
    while(true){
        data x = q.front();q.pop();
        if(x.value==1){
            cout << x.count << endl;
            return;
        }
        if(x.value%3==0) {
            q.push({x.value/3,x.count+1});
        }
        if(x.value%2==0) {
            q.push({x.value/2, x.count+1});
        }
        q.push({x.value-1, x.count+1});
 
    }
 
 
}
 
 
int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();
 
    return 0;
 
}