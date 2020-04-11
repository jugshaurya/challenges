#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int 			long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqmax            priority_queue<int>
#define pqmin             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007 // 1e9+7
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)	type *arr=new type[n];
#define w(t)            int t; cin>>t; while(t--)
#define pw(b,p)         pow(b,p) + 0.1
#define endl			"\n"

void fastIO(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// for kickstart comment last four lines
	#ifndef ONLINE_JUDGE	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

bool isOperator(char ch){
	return ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch=='^';
}

// a and b should be guarented to be operators
int prior(char a){

	switch(a){
		case '^': return 5;  
		case '*': return 5;  
		case '/': return 5;  
		case '+': return 4;  
		case '-': return 4;
		default: return 0;  
	}
}

void postfix_of_infix(string &s, int n){

	stack<char> myStack;
	for (int i = 0; i < n; ++i){
		char currentChar = s[i];

		if(currentChar>='A' && currentChar<='Z'){
			cout << currentChar << "";
			
		}else if(currentChar == ')') {
			while(!myStack.empty() && myStack.top() != '('){
				cout<<myStack.top()<<"";
				myStack.pop();				
			}
			if(!myStack.empty()){
				// remove the '(' from the top
				myStack.pop();
			}
		}else if(isOperator(currentChar)){
			while(!myStack.empty() && prior(currentChar) < prior(myStack.top())){
				cout<<myStack.top()<<"";
				myStack.pop();
			}
			myStack.push(currentChar);
		}else{
			myStack.push(currentChar);
		}
	}

	while(!myStack.empty()){
		cout<<myStack.top()<<"";
		myStack.pop();
	}
	cout<<endl;
}

int32_t main(){
	fastIO();
	/** code here */
	w(t){
		int n; cin>>n;
		string s;
		cin>>s;
		postfix_of_infix(s, n);
	}
	return 0;
}