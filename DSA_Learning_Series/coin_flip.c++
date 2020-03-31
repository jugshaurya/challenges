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
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void fastIO(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int32_t main(){
	fastIO();
	/** code here */

	w(x){
		int g; cin>>g;
		while(g--){
			int i,n,q;
			cin>> i >> n >>q;

			// start head
			if(i==1)
				if(n%2==0)
					if(q==1)
						// print head
						cout<<n/2<<"\n";
					else
						cout<<n/2<<"\n";
					
				else
					if(q==1)
						cout<<n/2<<"\n";
					else
						cout<<n/2+1<<"\n";
					
			else
				if(n%2==0)
					if(q==1)
						// print head
						cout<<n/2<<"\n";
					else
						cout<<n/2<<"\n";
					
				else
					if(q==1)
						cout<<n/2+1<<"\n";
					else
						cout<<n/2<<"\n";
					
		}
	}
	return 0;
}