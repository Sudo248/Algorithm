
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

vector<int>a;
int n;

void init(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n;i++) a[i] = i+1;
}

void print(){
    for(int i = 0; i < n; i++) cout << a[i];
    cout << ' ';
}


void solve(){
    init();
    do{
        print();
    }while(next_permutation(a.begin(),a.end()));
    cout << endl;
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}