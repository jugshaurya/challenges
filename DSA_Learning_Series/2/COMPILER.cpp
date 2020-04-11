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
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007 // 1e9+7
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)	type *arr=new type[n];
#define w(t)            int t; cin>>t; while(t--)
#define pw(b,p)         pow(b,p) + 0.1
#define endl			"\n"
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// for kickstart comment last four lines
	#ifndef ONLINE_JUDGE	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int32_t main(){
	fastIO();

	w(t){
		string s;
		cin>>s;
		
		stack<int> myStack;
		int prefix_length = 0;
		int longest_prefix_length = 0;
		int n = s.length();
		bool isBalanced = true;
		for (int i = 0; i < n; ++i){
			if(s[i] == '<'){
				prefix_length += 1;
				myStack.push('<');
			}else{
				if(myStack.empty()){
					longest_prefix_length = max(longest_prefix_length, prefix_length);
					// cout<<longest_prefix_length<<"||"<<endl;
					break;
					isBalanced = false;
					prefix_length  = 0;
				}else{
					prefix_length += 1;
					// longest_prefix_length = max(longest_prefix_length, prefix_length);
					myStack.pop();
				}
			}
		}

		if(myStack.empty() and isBalanced){
			cout<<n<<endl;
			// cout<<endl;
		}else{
			cout<<longest_prefix_length<<endl;
			// cout<<endl;;
		}
	}

	return 0;
}