
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
	vector< int> v{0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1};
	w(t){
		int n;
		cin>>n;
		int logn = floor(log2(n));
		int nthFibmod10 = pow(2, logn);
		cout<<v[(nthFibmod10%v.size()) - 1]<<endl;

	}
	return 0;
}




/**

Repeated Squence:
0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1,
Algo: 
find out 2^(floor(log(n)))th fibonacci number 

n = 9
D = 0 1 1 2 3 5 8 3 1
	1 2 5 3
	2 3
	3
log2(n) = 3


n = 10
D = 0 1 1 2 3 5 8 3 1 4
	1 2 5 3 4
	2 3 
	3
log2(n) = 3

n = 11
D = 0 1 1 2 3 5 8 3 1 4 5
	1 2 5 3 4
	2 3 
	3
log2(n) = 3


n = 12
D = 0 1 1 2 3 5 8 3 1 4 5 9							
	1 2 5 3 4 9
	2 3 9
	3
log2(n) = 3


n = 13
D = 0 1 1 2 3 5 8 3 1 4 5 9 4			
	1 2 5 3 4 9
	2 3 9
	3
log2(n) = 3


n = 14
D = 0 1 1 2 3 5 8 3 1 4 5 9 4 3	
	1 2 5 3 4 9 3
	2 3 9
	3
log2(n) = 3

n = 15
D = 0 1 1 2 3 5 8 3 1 4 5 9 4 3 7											
	1 2 5 3 4 9 3
	2 3 9
	3
log2(n) = 3


n = 16
D = 0 1 1 2 3 5 8 3 1 4 5 9 4 3 7 0			
	1 2 5 3 4 9 3 0
	2 3 9 0
	3 0
	0
log2(n) = 4

*/