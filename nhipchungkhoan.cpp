#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    int n;
    cin >> n;
    vector<int>a(n), b(n+1);
    stack<int>st;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++){
        while(st.size() && a[i] >= a[st.top()] ) st.pop();
        if(st.empty()) b[i] = 0;
        else b[i] = st.top()+1;
        st.push(i);
        
    }
    for(int i=0;i<n;i++) cout << i-b[i]+1 << ' ';
    cout << endl;


}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}