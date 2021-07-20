#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){

    stack<char>front,back;
    string s;
    cin >> s;
    for(char c:s){
        if(c == '<'){
            if(front.size()){
                back.push(front.top());
                front.pop();
            }
        }
        else if(c == '>'){
            if(back.size()){
                front.push(back.top());
                back.pop();
            }
        }
        else if(c == '-'){
            if(front.size())
                front.pop();
        }
        else{
            front.push(c);
        }
    }

    while(front.size()){
        back.push(front.top());
        front.pop();
    }

    while(back.size()){
        cout << back.top();
        back.pop();
    }
    cout << endl;

}


int main(){
    faster
    solve();

    return 0;

}