// Bracket Match

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
	int n;
	cin>>n;

	// first int for brace and secondint for index
	stack<pii> myStack;
	int data;
	int depth = 0;
	int maxDepth = -inf;
	int possibleMaxDepthStartingIndex = 0;
	int confirmedMaxDepthStartingIndex = 0;

	int number_of_symbols = 0;
	int max_number_of_symbols = -inf;
	int start_max_number_of_symbols = 0;
	for (int i = 0; i < n; ++i){
		cin>>data;
		if(data == 1){
			myStack.push({data, i+1});
			depth = 0;
		}else{
			
			/* depth logic */
			// since s is balanced stack cant be empty!
			depth += 1;
			if(depth == 1){
				possibleMaxDepthStartingIndex = myStack.top().second;
			}
			if(depth > maxDepth){
				maxDepth = depth;
				confirmedMaxDepthStartingIndex  = possibleMaxDepthStartingIndex;
			}

			/* number of symbol logic */
			number_of_symbols = (i+1) - myStack.top().second + 1;
			if(number_of_symbols > max_number_of_symbols){
				max_number_of_symbols = number_of_symbols;	
				start_max_number_of_symbols = myStack.top().second;		
			}
			myStack.pop();
		}
	}

	cout<<maxDepth<<" "<<confirmedMaxDepthStartingIndex<<" ";
	cout<<max_number_of_symbols<<" "<<start_max_number_of_symbols<<endl;
	return 0;
}