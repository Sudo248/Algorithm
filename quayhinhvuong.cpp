#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int rotateLeft[] = {3,0,2,4,1,5};
int rotateRight[] = {0,4,1,3,5,2};

string rotate(string s, bool isRotateLeft){
    string res ="";
    if(isRotateLeft){
        for(int i=0;i<6;i++) res += s[rotateLeft[i]];
    }
    else{
        for(int i=0;i<6;i++) res += s[rotateRight[i]];
    }
    return res;
}

void solve(){

    string start, finish;
    char c;
    for(int i=0;i<6;i++){
        cin >> c;
        start += c;
    }
    for(int i=0;i<6;i++){
        cin >> c;
        finish += c;
    }

    set<string> set;
    queue<pair<string, int> >q;
    q.push({start, 0});
    set.insert(start);

    while(q.size()){
        auto tmp = q.front(); q.pop();
        if(tmp.first == finish){
            cout << tmp.second << endl;
            return;
        }
        string left = rotate(tmp.first, true);
        string right = rotate(tmp.first, false);
        if(set.count(left) == 0){
            q.push({left, tmp.second +1});
            set.insert(left);
        }
        if(set.count(right) == 0){
            q.push({right, tmp.second +1});
            set.insert(right);
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