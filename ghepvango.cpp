#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;


void solve(){
    stack<int>st;
    int n;
    cin>>n;
    vector<int> a(n),L(n),R(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        while (!st.empty() && a[i] <= a[st.top()]) st.pop(); 
        if(st.empty()) L[i]=0;
        else L[i]=st.top()+1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[i] <= a[st.top()]) st.pop();
        if(st.empty()) R[i]=n-1;
        else R[i]=st.top()-1;
        st.push(i);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(a[i]<=R[i]-L[i]+1) ans=max(ans,a[i]);
    }
    cout<< ans << endl;

}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}