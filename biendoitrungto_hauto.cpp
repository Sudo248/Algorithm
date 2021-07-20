#include <bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  endl '\n'
#define ll long long
using namespace std;
int process(char c) {
    if( c == '(') return 0;
	if( c == '+' || c == '-' ) return 1;
	if( c == '*' || c == '/' || c == '%' ) return 2;
	if( c == '^' ) return 3;
    return 4;
}
void solve(){
    stack<char> st;
	string s, str = "";
	cin >> s;
	for(char c:s){
		if (c != ' '){
			if((c>='0' && c<='9') || (c>='a' && c<='z') || (c>='A' && c<='Z')) str += c;
			else{
				cout<< str;
				str = "";
				if( c == '(') st.push(c);
				else {
					if(c == ')') {
						while(st.top()!= '('){
							cout<< st.top();
							st.pop();
						}
						if(st.top() == '(') st.pop();
					}
					else{
						while(!st.empty() && process(c) <= process(st.top())){
							cout<< st.top();
							st.pop();
						}
						st.push(c);
					}
				}
			}
		}
	}
	if( str != "" ) cout<< str;
	while(!st.empty()){
		if(st.top()!= '(') cout<< st.top();
		st.pop();
	}
    cout << endl;
}

int main(){
    faster
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;    
}