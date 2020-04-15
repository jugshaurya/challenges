#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int 			long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int, int>
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
#define fo(i,n)			for(int i =0; i<n; i++)
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

const int N = 2*1e5 +1 ;
int narr[N];
int marr[N];

int32_t main(){
	fastIO();
	/** code here */
	int n,m;
	cin>>n>>m;

	// O(n^2)
	fo(i,n)
		cin>>narr[i];
	fo(i,m)
		cin>>marr[i];
	
	// chooose N+M−1  pairs
	map<int, pii > myMap;
	fo(i,n){
		fo(j,m){
			myMap[narr[i] + marr[j]] = mp(i,j);
		}
	}

	int total = 0;
	for(auto ele : myMap){
		int key = ele.first;
		pii index = ele.second;
		cout<< index.first<<" "<<index.second<<endl;
		total += 1;
		if(total == n + m -1){
			break;
		}
	}


	return 0;
}