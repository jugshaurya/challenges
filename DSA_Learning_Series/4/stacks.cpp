// https://www.codechef.com/LRNDSA04/problems/STACKS
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

	// observations  and crux of question
	// top-most disk will have the smallest radius than the next one.
	// 5 2 1 ->valid
	// 4 5 1 -> invalid

	// { } -> need to place => si
	// si should be placed on the stack with min(top-si) s.t. (top-si)>0
	// else a new stack is created and added to the set

	// example
	// 3 4 5 1 1 2 => order
	// {1 1 2}
	
	// 4 3 5 1 1 2 => order
		// {1, 1, 2}
	// {1 1 2}

	// 1. **result is always going to be sorted all the time**, because all big ones are going in the end and all smaller ones are replacing the already one with more smaller item. 

	// 2. can use binary search to find out the index where a replacement should happen

	// How to proceed
	// for every new value(ai),I have to find out the minimal value greater than the current value.
	//  simple vector is required or use array with size 10^5


	/** code here */


	w(t){
		vi ans;
		int n; cin>>n;
		int data; cin>>data;
		ans.pb(data);
		for (int i = 1; i < n; ++i){
			cin>>data;

			// O(n) - not accepted TLE
			// int j = 0;
			// while(j<ans.size()){
			// 	if (data < ans[j]) {
			// 		ans[j] = data;
			// 		break;
			// 	}
			// 	j++;
			// }
			// if (j==ans.size()) ans.pb(data);

			// 1. O(logn)
			// int start = 0;
			// int end = ans.size()-1;
			// int index = -1;
			// // find out the very first value greater than data
			// while(start<=end){
			// 	// cout<<"sd"<<start<<" "<<end<<endl;
			// 	int mid = (start+end)/2;
			// 	if(ans[mid] > data ){
			// 		index = mid;
			// 		end =  mid-1;
			// 	}else{
			// 		// cout<<"s";
			// 		start = mid+1;
			// 		// cout<<start<<endl;
			// 	}

			// }
			// if(index == -1) ans.pb(data);
			// else ans[index] = data;

			// 2. O(logn) stl
			int index = upper_bound(ans.begin(), ans.end(), data)-ans.begin();
			if(index < ans.size()) ans[index] = data;
			else ans.pb(data);
		}

		cout<<ans.size()<<" ";
		for(int x : ans){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}