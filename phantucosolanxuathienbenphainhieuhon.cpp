#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define MAX int(1e6)
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    vector<int>a(n),dd(MAX,0), res(n);
    stack<int>st;
    for(int &i:a){
        cin >> i;
        dd[i]++;
    }
    for(int i=n-1;i>=0;i--){
        while(st.size() && dd[a[i]] >= dd[st.top()]) st.pop();
        if(st.empty()) res[i] = -1;
        else res[i] = st.top();
        st.push(a[i]);
    }
    for(int &i:res) cout << i << ' ';
    cout << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}