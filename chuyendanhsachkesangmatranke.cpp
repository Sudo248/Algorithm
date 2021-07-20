#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int to_int(string s){
    int tmp = 0;
    for(char &c:s){
        tmp = tmp * 10 + (c-'0');
    }
    return tmp;
}
void solve(){

    int n;
    cin >> n;
    cin.ignore();
    int a[1001][1001]={0};
    for(int i=1;i<=n;i++){
        string s,tmp = "";
        getline(cin,s);
        s+=' ';
        for(char &c:s){
            if(c==' '){
                a[i][to_int(tmp)] = 1;
                tmp = "";
            }
            else tmp += c;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }

}


int main(){
    faster
    solve();

    return 0;

}