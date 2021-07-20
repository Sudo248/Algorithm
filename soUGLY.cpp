// cach 2
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<ll>ugly;

void prepare(){
    ugly.push_back(1);
    int x2=0,x3=0,x5=0;
    for(int i=1;i<=10000;i++){
        ugly.push_back(min(ugly[x2]*2, min(ugly[x3]*3, ugly[x5]*5)));
        if(ugly.back() == ugly[x2]*2) x2++;
        if(ugly.back() == ugly[x3]*3) x3++;
        if(ugly.back() == ugly[x5]*5) x5++;
    }
}

void solve(){

    int n;
    cin >> n;
    cout << ugly[n-1] << endl;

}


int main(){
    faster
    prepare();
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}
/*
cach 1: 
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<ll>ugly;

void prepare(){
    set<ll>tmp;
    tmp.insert(1);
    int i=0;
    set<ll>::iterator iter = tmp.begin();
    while(true){
        ll x = *iter;
        ugly.push_back(x);
        if(i++ >= 10001) return;
        tmp.insert(x*2);
        tmp.insert(x*3);
        tmp.insert(x*5);
        iter++;
    }
}

void solve(){

    int n;
    cin >> n;
    cout << ugly[n-1] << endl;
    // for(int i=0;i<11;i++) cout << ugly[i] << ' ';

}


int main(){
    faster
    prepare();
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}*/