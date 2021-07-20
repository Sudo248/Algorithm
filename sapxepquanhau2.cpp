
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int a[11][11], dd[11][11];
int res, dem;

bool check(int x,int y){

    int i=x,j=y;

    while (i>=0) {
        if(dd[i][j]) return false;
        i--;
    }

    i=x,j=y; 
    while(i>=0 && j>=0) {
        if(dd[i][j]) return false;
        i--;
        j--;
    }
    i=x,j=y;
    while(i>=0 && j<8){
        if(dd[i][j]) return false;
        i--;
        j++;
    }
    return true;
    
}

void Try(int i, int s){

    for(int j = 0; j < 8; j++){
        if(check(i,j)){
            dd[i][j] = 1;
            s += a[i][j];
            if(i == 7){
                res = max(res, s); 
            }
            else{
                Try(i+1, s);
            }
            s -= a[i][j];
            dd[i][j] = 0;
        }
    }
    // i--;
    
}

void solve(){

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> a[i][j];
            dd[i][j] = 0;
        }
    }

    res = 0;
    dem = 0;

    Try(0,0);

    cout << res << endl;

}

int main(){
    // faster
    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}