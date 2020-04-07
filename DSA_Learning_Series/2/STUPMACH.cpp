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

piii findMinEle_focc_locc(arr,n){

	piii t;
	int f_occ = 0;
	int l_occ = -1;
	int minEle = 1e9;
	for (int i = 0; i < n; ++i){
		if(arr[i]< minEle){
			minEle = arr[i];
			f_occ = i;
		}
		if(arr[i]== minEle){
			l_occ = i;
		}
	}

	return t(minEle, mp(f_occ, l_occ));
} 

int32_t main(){
	fastIO();
	/** code here */
	w(t){
		int n;cin>>n;
		for (int i = 0; i < n; ++i){
			/* code */
			cin>>arr[i];
		}

		int total_tokens = 0;
		piii t = findMinEle_focc_locc(arr,n);
		int minEle = t->first ;
		int f_occ = t->second->first ;
		int l_occ = t->second->second ;
		cout<<minEle<<f_occ<<l_occ;

	}
	return 0;
}