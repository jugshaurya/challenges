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

const int N = 100000+1;
const int K = 6;

int kprimeSieve[N];
int prefixSumWithK[N+1][K];

void fillSieve(){
	kprimeSieve[0] = 0;
	kprimeSieve[1] = 0;
	for (int i = 2; i <N; ++i){
		if(kprimeSieve[i] == 0) {
			for (int j = i; j < N; j+=i){
				kprimeSieve[j] += 1;
			}			
		}
	}

	for (int i = 2; i < N+1; ++i){
		for (int j = 1; j < K; ++j) {
			if(j == kprimeSieve[i]){
				prefixSumWithK[i][j] = prefixSumWithK[i-1][j] + 1;
			}else{
				prefixSumWithK[i][j] = prefixSumWithK[i-1][j];
			}
		}
	}
}

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
	/** code here */
	fillSieve();
	w(t){
		int a,b,k; cin>>a>>b>>k;
		cout<<prefixSumWithK[b][k]-prefixSumWithK[a-1][k]<<endl;
		
	}
	return 0;
}

