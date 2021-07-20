#include<bits/stdc++.h>
#define ll long long
#define N 10
 
using namespace std;
 
int d,dem;
int n;
int b[N][N];
 
bool ok(int b[][N], int row, int col){
	int i,j;
 
	// hàng ngang
	for (int j=0; j<col; j++){
		if(b[row][j] == 1) 
			return false;
	}
 
	// chéo trên 
	i=row;
	j=col;
	while(i>=0 && j>=0){
		if(b[i][j] == 1){
			return false;
		}
		i--;
		j--;
	}
 
	// chéo duoi
	i=row, j=col;
	while(i<n && j>=0){
		if(b[i][j] == 1){
			return false;
		}
		i++;
		j--;
	}
	return true;
}
 
bool setq(int b[][N], int col){
	for (int j=0; j<n; j++){
		if(ok(b,j,col)) return true;
	}
	return false;
}
 
int Try(int i){
	for (int j=0; j<n; j++){
		if(ok(b,j,i)){
			b[j][i] = 1;
			if(setq(b,i+1)){
				if(i+1 == n-1){
					dem++;
					return d += dem;
				}
				else Try(i+1);
			}
			else{
				b[j][i] = 0;
			}	
		}
	}
}
 
void solve(){
	for (int i=0; i<n; i++){
		dem = 0;
		b[i][0] = 1;
		Try(1);
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				b[i][j] = 0;
			}
		}
	}
	cout << d << endl;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin >> t;
	while(t--){
		d = 0;
		cin >> n;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				b[i][j] = 0;
			}
		}		
		solve();
	}
}
 