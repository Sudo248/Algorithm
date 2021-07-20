
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,x;
    cin>>n;
    deque<int>dq;
    string s;
    while(n--){
        cin>>s;
        if(s == "PUSHBACK"){
            cin>>x;
            dq.push_back(x);
        }
        else if(s == "PUSHFRONT"){
            cin>>x;
            dq.push_front(x);
        }
        else if(s == "PRINTFRONT"){
            if(dq.size())
                cout<<dq.front()<<endl;
            else cout<<"NONE\n";
        }
        else if(s == "POPFRONT"){
            if(dq.size()) dq.pop_front();
        }
        else if(s == "PRINTBACK"){
            if(dq.size())
                cout<<dq.back()<<endl;
            else cout<<"NONE\n";
        }
        else{
            if(dq.size())
                dq.pop_back();
                
        }
    }
}

int main(){
    faster

    solve();

    return 0;
}