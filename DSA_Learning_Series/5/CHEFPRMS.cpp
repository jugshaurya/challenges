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

vi getSemiPrimes(){
	vi semi; 
	for (int i = 2; i <= 201; ++i){
		bool gotcha = true;
		int count = 0; 
		int n = i;
		for (int j = 2; j <= sqrt(n); j+=1){
			if(n%j==0) {
				n /= j;
				count += 1;
				if(n%j==0){
					gotcha = false;
					break;	
				}
			}
		}
		if(!gotcha) continue;
		if(n>1){
			count++;
		}

		if(count == 2){
			semi.pb(i);
		}
	}

	return semi;
}

int32_t main(){
	fastIO();
	// find all the semi primes number between 1 and N
	// then find all possible sums that can be generated
	// and later check if n exist or not in this psums.

	vi semi = getSemiPrimes();
	map<int, bool > psums;
	for (int i = 0; i < semi.size(); ++i){
		for (int j = 0; j < semi.size(); ++j){
			int sum = semi[i] + semi[j];
			psums[sum] = true;
		}
	}

	w(t){
		int n; cin>>n;
		if(psums.count(n)==1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}