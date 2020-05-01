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

void findPattern(){
	int x = 11;
	int y = 2600; 
	int l = 0;
	int r = 10000;
	int maxi = -inf;
	int last = 0;
	int maxiValue = -1;
	for (int i = l; i <=r; ++i){
		int value = (x&i)*(y&i);
		// if(value==324) {

		// 	cout<<i-last<<endl;
		// 	last = i;
		// }
		cout<<i<<" "<<value<<endl;
		if(value > maxi){
			maxi = value;
			maxiValue = i;
		}
	}

	// cout<<maxiValue<<endl;
}

// maximum possible value is always x*y ex-12*206 = 2472
// overall max value is at z = 2^max(logx, logy)-1
// then found on  z+(z+1), z+2*(z+1)
// if z=31
// 31 63 95....
int32_t main(){
	fastIO();
	/** code here */
	findPattern();
	w(t){
		int x,y,l,r; cin>>x>>y>>l>>r;
		// int maxi = -inf;
		// int maxiValue=-1;
		// for (int i = l; i <=r; ++i){
		// 	int value = (x&i)*(y&i);
		// 	if(value > maxi){
		// 		maxi = value;
		// 		maxiValue = i;
		// 	}
		// }
		// cout<<maxiValue<<endl;
	}
	return 0;
}