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

int32_t main(){
	fastIO();
	/** code here */
	w(t){
		int n,k; cin>>n>>k;
		int* arr = new int[n];
		int* peak = new int[n];
		int* prePeak = new int[n+1];
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
		}

		peak[0] = 0;
		for (int i = 1; i < n-1; ++i){
			if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
				peak[i] = 1;
			}else{
				peak[i] = 0;
			}
		}


		prePeak[0] = 0;
		for (int i = 1; i < n; ++i){
			prePeak[i] = prePeak[i-1] + peak[i-1];
		}

		int maxi = -1e9;
		int index = -1;
		for (int i = k-1; i < n; ++i){
			int peaks = prePeak[i] - prePeak[i-k+1];
			if(peaks > maxi){
				maxi = peaks;
				index = i-k+2; 
			}
		}

		// 0 0 0 1 1 1 2 2 2 2 2
		cout<<maxi+1<<" "<<index<<endl;
	}
	return 0;
}
