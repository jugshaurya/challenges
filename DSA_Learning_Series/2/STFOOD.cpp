#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define w(t)            int t; cin>>t; while(t--)
#define endl			"\n"
// mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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
	const int N = 100;
	int* arr = new int[N];
	printArray(arr,N);
	for (int i = 2; i < N; ++i){
		for (int j = 2; j < N; ++j){
			for (int k = 2; k < N; ++k){
				if(i*j*k<N){
					arr[i*j*k] = 1;
				}
			}
		}
	}
	cout<<"==========8="<<endl;
	for (int i = 0; i < N; ++i){
		if(arr[i]==1){
			cout<<i<<" ";
		}
	}
	cout<<"=========="<<endl;

	return 0;
}