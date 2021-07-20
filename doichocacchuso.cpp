
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int k;
    string s;
    cin >> k >> s;
    int len = s.length();
    for(int i = 0; i < len-1; i++){
        char Max = s[len-1];
        int x = i+1;
        for(int j = i+1; j < len; j++){
            if(Max <= s[j]){
                Max = s[j];
                x = j;
            }
        }
        if(Max > s[i] && k > 0){
            swap(s[x], s[i]);
            k--;
        }


    }

    cout << s << endl;

}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}