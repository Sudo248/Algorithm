#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<int> Index;
bool stop;
int n,k;

void print(){
    string tmp = "";
    for(int j=1;j<=k;j++){
        tmp += char('A'+Index[j]-1);
    }
    cout << tmp << '\n';
}

void ToHop(){
    int i = k;
    while(i>=1 && Index[i] == n-k+i) i--;
    if(i < 1) stop = true;
    else{
        Index[i]++;
        for(int j=i+1;j<=k;j++) 
            Index[j] = Index[j-1]+1;
    }
}

void solve(){

    Index.clear();
    Index.resize(21);
    stop = false;
    cin >> n >> k;
    for(int i=1;i<=k;i++) 
        Index[i] = i;
    while(!stop){
        print();
        ToHop();
    }



}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}