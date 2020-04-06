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

void printArray(int* arr, int n){
	cout<<"=========="<<endl;
	for (int i = 0; i < n; ++i){
		cout<<arr[i]<<" ";
	}
	cout<<"=========="<<endl;
}

void fastIO(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// for kickstart comment last four lines
	#ifndef ONLINE_JUDGE	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
const int N = 1e5;
int dp[N];
int maxProfit(vi& prices, int start) {

	if(dp[start] != 0) return dp[start];
	int end = prices.size();
	int maxProfitValue = 0;
	for (int i = start; i < end-1; ++i){
		for(int j = i+1; j < end; j++){
			int restResult = 0 ? j+1 > end : maxProfit(prices, j+1);
			maxProfitValue = max(maxProfitValue, prices[j] - prices[i] + restResult);
			dp[start] = maxProfitValue;
		}
	}

	return dp[start];
}

int32_t main(){
	fastIO();
	memset(dp,0,sizeof(dp));
	vi v;
	v.pb(7);
	v.pb(1);
	v.pb(5);
	v.pb(3);
	v.pb(6);
	v.pb(4);

	// v.pb(1);
	// v.pb(2);
	// v.pb(3);
	// v.pb(4);
	// v.pb(5);

	// v.pb(7);
	// v.pb(6);
	// v.pb(4);
	// v.pb(3);
	// v.pb(1);

	// 1 for buy
	// -1 for sell
	// initially we have to buy a stock.
	cout<<maxProfit(v, 0);
	printArray(dp,7);

	return 0;
}









// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
        
//     }
// };


const int N = 1e7;
int dp[N];            
// class Solution {
// public:
//     int maxProfitHelper(vector<int>& prices, int start, int* dp) {
//         if(dp[start] != 0) return dp[start];
//         int end = prices.size();
//         int maxProfitValue = 0;
//         for (int i = start; i < end-1; ++i){
//             for(int j = i+1; j < end; j++){
//                 int profit = prices[j] - prices[i];
//                 int restResult = 0 ? j+1 > end : maxProfitHelper(prices, j+1, dp);
//                 maxProfitValue = max(maxProfitValue, profit + restResult);
//                 dp[start] = maxProfitValue;
//             }
//         }
//         return dp[start];
//     }

//     int maxProfit(vector<int>& prices) {
//         memset(dp,0,sizeof(dp));
//         return maxProfitHelper(prices, 0, dp);
//     }
// };