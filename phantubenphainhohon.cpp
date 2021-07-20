#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    stack<int>st;
    vector<int>MaxRight(n), MinRight(n);
    for(int i=n-1;i>=0;i--){
        while(st.size() && a[i] >= st.top()) st.pop();
        if(st.empty()) MaxRight[i] = -1;
        else MaxRight[i] = st.top();
        st.push(a[i]);
    }
    while(st.size()) st.pop();
    // for(int i=0;i<n;i++) cout<<MaxRight[i] << ' ';
    // cout << endl;

    // for(int i=n-1;i>=0;i--){
    //     if(st.empty()){
    //         st.push(a[i]);
    //         MinRight[i] = -1;
    //     }
    //     else{
    //         while(st.size() && a[i] <= st.top()) st.pop();
    //         if(st.empty()) MinRight[i] = -1;
    //         else MinRight[i] = st.top();
    //         st.push(a[i]);
    //     }
    // }
    // for(int i=0;i<n;i++) {
    //     if(MaxRight[i] == -1){
    //         cout << -1 << ' ';
    //     }
    //     else cout<<MinRight[MaxRight[i]] << ' ';
    // }
    // cout << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}