#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;


void solve(){

    int n;
    cin >> n;
    vector<int>ts(1000006,0), a(n), res(n);
    stack<int>st;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ts[a[i]]++;
    }
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && ts[a[i]] >= ts[a[st.top()]]) st.pop();
        if(st.empty()) res[i] = -1;
        else res[i] = a[st.top()];
        st.push(i);
    }

    for(int i:res) cout << i <<' ';
    cout << endl;


}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}