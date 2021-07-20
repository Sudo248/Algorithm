#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int dem,n,k;
bool stop;
vector<int>a,b;

void sinhketiep(){
    int i=k;
    while(i>0 && b[i] == n-k+i) i--;
    if(i==0){
        stop = true;
    }
    else{
        b[i]++;
        for(int j=i+1;j<=k;j++){
            b[j] = b[j-1]+1;
        }
    }
}

void print(){
    for(int i=2;i<=k;i++){
        if(a[b[i]] <= a[b[i-1]]) return;
    }
    dem++;
    // cout <<endl;
}

void tohop(){
    while(!stop){
        print();
        sinhketiep();
    }
}

void solve(){
    cin >> n >> k;
    a.resize(n+1);
    b.resize(k+1);
    dem = 0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++) b[i] = i;
    stop = false;
    tohop();
    cout << dem << endl;

}


int main(){
    faster
    solve();

    return 0;

}