#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define MAX int(1e5)

vector<bool>a(MAX,false);
vector<int> res(MAX,0);

bool check(int n){
	bool dd[6] = {0};
	while(n){
		int tmp = n%10;
		n/=10;
		if(tmp > 5) return false;
		if(dd[tmp]) return false;
		dd[tmp] = true;
	}
	return true;
}

void prepare(){
	res[0] = 1;
	for(int i=1;i<=MAX;i++){
		if(check(i)) res[i] = res[i-1] + 1;
		else res[i] = res[i-1];
	}
}

void solve(){

	int l,r;
	cin >> l >> r;
	cout << res[r] - res[l-1] << endl;

}


int main(){
	faster
	prepare();
	int t;
	cin >> t;
	while(t--) solve();

	return 0;

}