#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct data{
    int value, count;
};

void solve(){

    int S,T;
    cin >> S >> T;
    if(S>=T){
        cout << S-T <<endl;
        return;
    }
    queue<data>q;
    vector<bool>dd(20004,false);
    q.push({S,0});
    while(true){
        data tmp = q.front();q.pop();
        if(tmp.value == T){
            cout << tmp.count << endl;
            return;
        }
        if(tmp.value -1 == T | tmp.value*2 == T){
            cout << tmp.count+1 << endl;
            return;
        }
        if(!dd[tmp.value*2] && tmp.value < T){
            q.push({tmp.value*2,tmp.count+1});
            dd[tmp.value*2] = true;
        }
        if(!dd[tmp.value-1] && tmp.value > 1){
            q.push({tmp.value-1,tmp.count+1});
            dd[tmp.value-1] = true;
        }
    }

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}