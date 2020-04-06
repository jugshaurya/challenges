// https://www.codechef.com/IIITDS20/problems/MAY19F1
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
#define w(x)            int x; cin>>x; while(x--)
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

const int N = 1e5;
int arr[N];
int preMax[N];
int32_t main(){
	fastIO();
	/** code here */
	w(t){
		int n,q; cin>>n>>q;
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
			if(i==0) preMax[0] = arr[i];
			else preMax[i] = max(preMax[i-1], arr[i]);
		}

		int ele;
		for (int i = 0; i < q; ++i){
			cin>>ele;
			cout<<preMax[ele-1]<<endl;

		}
	}
	return 0;
}