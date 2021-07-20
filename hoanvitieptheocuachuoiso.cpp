
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    string s;
    int n;
    cin >> n >> s;
    cout << n << ' ';
    int i = s.length()-2;
    while(i >= 0 && s[i] >= s[i+1]) i--;

    if(i < 0) cout << "BIGGEST\n";
    else{
        int j = s.length();
        while(j > i && s[j] <= s[i]) j--;
        swap(s[i],s[j]);
        int l = i+1, r = s.length() - 1;
        while(l <= r){
            swap(s[l],s[r]);
            l++;r--;
        }
        cout << s << endl;
    }

    
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}