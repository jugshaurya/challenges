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
#define piii			pair<int,pii>
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

const int N = 1e6 + 1;
int arr[N];

// O(n) : Time complexity

pii getTokensForSubarrayAndReduceTokens(int* arr, int n){
	// find min from the back
	int minIndex = n-1;
	int minEle = arr[n-1];
	for (int i = n-2; i >= 0; --i){
		if(arr[i] < minEle){
			minEle = arr[i];
			minIndex = i;
		}

		if(arr[i] == 0){
			minEle = 0;
			minIndex = i;
		}
	}

	for (int i = n; i >= 0; --i){
		arr[i] -= minEle;
	}

	return mp(minIndex, minEle);
}

int32_t main(){
	fastIO();
	w(t){
		int n; cin >> n;
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
		}

		int size = n; 
		int number_of_tokens = 0 ;
		while(size > 0 ) {
			pii result = getTokensForSubarrayAndReduceTokens(arr, size);
			int minIndex = result.first;
			int minEle = result.second;
			number_of_tokens += (size) * minEle;
			size = minIndex;
		}
		cout<<number_of_tokens<<endl;
	}
	return 0;
}