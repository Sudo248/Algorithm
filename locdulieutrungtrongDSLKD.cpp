#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[10005], ts[10005] = {0};
    for(int i=0;i<n;i++){
        cin >> a[i];
        ts[a[i]]++ ;
    }
    for(int i=0;i<n;i++){
        if(ts[a[i]] != 0 ) {
            cout << a[i] << ' ';
            ts[a[i]] = 0;
        }
    }
    
    
    return 0;
}