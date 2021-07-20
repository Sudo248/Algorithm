#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<int>a;
vector<vector<int> >res;
int m;
void print(vector<int>b){
    cout << "(";
    for(int i=1;i<b.size()-1;i++) cout << b[i] << ' ';
    cout << b.back() << ") ";
}
void process(){

}
void Try(int s){
    for(int i=a.back();i>=1;i--){
        if(s+i <= m){
            a.push_back(i);
            if(s+i == m){
                res.push_back(a);
            }
            else Try(s+i);
            a.pop_back();
        }
    }
}

void solve(){

    a.clear();
    res.clear();
    cin >> m;
    a.push_back(m);
    Try(0);
    cout << res.size() << endl;
    for(vector<int> i:res){
        print(i);
    }
    cout << endl;


}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}