#include<iostream>
using namespace std;
int main(){
    int n;
    int a[10005];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    int k;
    cin >> k;
    for(int i=0;i<n;i++){
        if(a[i] != k) cout << a[i] << ' ';
    }
    return 0;
}