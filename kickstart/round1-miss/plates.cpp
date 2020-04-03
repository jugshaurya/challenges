#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int 			long long
#define ff              first
#define ss              second
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
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define endl			"\n"
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void fastIO(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// for kickstart comment last four lines
// 	#ifndef ONLINE_JUDGE	
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// 	#endif
}

int sum[50][30]={0};
int dp[50][1500];

int solve(int ws, int n, int k, int pl){

	if(ws == n) 
		return 0;
	
	if(dp[ws][pl]!=-1){
	    return dp[ws][pl];
	}
	
	int result = solve(ws+1, n, k, pl);
	for (int i = 1; i <= k; ++i)
		if(pl-i>=0)
			result = max(result, solve(ws + 1, n, k, pl-i) + sum[ws][i-1]);
			
    dp[ws][pl] = result;
	return result;
}

int32_t main(){
	fastIO();
	/** code here */
    int t;
    cin>>t;
    int tc = t;
	while(t--){

		int n,k,p; cin>>n>>k>>p;
		for (int i = 0; i < n; ++i){
			cin>>sum[i][0];
			for (int j = 1; j < k; ++j){
				cin>>sum[i][j];
				sum[i][j] += sum[i][j-1];
			}
		}

		for (int i = 0; i < 50; ++i){
			for (int j = 0; j < 1500; ++j){
			    dp[i][j] = -1;
			}
		}

        cout<<"Case #"<<tc-t<<": "<<solve(0, n, k, p)<<endl;
	}
	return 0;
}