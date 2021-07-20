#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
 
void solve(){
 
    int a,b,c;
    cin >> a >> b >> c;
    vector<int>A(a), B(b), C(c), res;
    for(int &i:A) cin  >> i;
    for(int &i:B) cin >> i;
    for(int &i:C) cin >> i;
    int ai=0,bi=0,ci=0;
 
    while(ai < a && bi < b && ci < c){
        if(A[ai] == B[bi] && B[bi] == C[ci]){
            res.push_back(A[ai]);
            ai++;
            bi++;
            ci++;
        }
        else {
            if(A[ai] >= B[bi] && A[ai] >= C[ci]){
                if(A[ai] > B[bi]) bi++;
                if(A[ai] > C[ci]) ci++;
            }
            else if(B[bi] >= A[ai] && B[bi] >= C[ci]){
                if(A[ai] < B[bi]) ai++;
                if(B[bi] > C[ci]) ci++;
            }
            else if(C[ci] >= B[bi] && A[ai] <= C[ci]){
                if(C[ci] > B[bi]) bi++;
                if(A[ai] < C[ci]) ai++;
            }
 
        }
    }
 
    if(res.size() == 0){
        cout << "NO\n";
    }
    else{
        for(int i:res) cout << i << ' ';
        cout << endl;
    }
 
}
 
 
int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();
 
    return 0;
 
}