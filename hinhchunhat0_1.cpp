#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int a[501][501];
int n,m;
ll res;

void findMax(vector<int>b){

    stack<int>st;
    vector<int>L(m,0),R(m,0);

    for(int i=0;i<m;i++){
        while(st.size() && b[i] <= b[st.top()]) st.pop();
        if(st.empty()) L[i] = 0;
        else L[i] = st.top()+1;
        st.push(i);
    }
    while(st.size()) st.pop();
    for(int i=m-1;i>=0;i--){
        while(st.size() && b[i] <= b[st.top()]) st.pop();
        if(st.empty()) R[i] = m-1;
        else R[i] = st.top()-1;
        st.push(i);
    }

    for(int i=0;i<m;i++){
        res = max(res, (ll)b[i]*(R[i]-L[i]+1));
    }
}

void solve(){

    cin >> n >> m;
    
    vector<int>b(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]) b[j] += a[i][j]; 
            else b[j] = 0;
        }
        findMax(b);
    }
    
    cout << res << endl;



}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}