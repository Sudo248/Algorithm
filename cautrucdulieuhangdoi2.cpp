
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    string s;
    int n;
    queue<int>q;
    cin>>n;
    while(n--){
        cin>>s;
        if (s == "PUSH"){
            int x;
            cin>>x;
            q.push(x);
        }
        else if(s=="PRINTFRONT"){
            if(q.size()){
                cout<<q.front()<<endl;
            }
            else{
                cout<<"NONE\n";
            }
        }
        else{
            if(q.size()) q.pop();
        }
    }
}

int main(){
    faster

    solve();

    return 0;
}