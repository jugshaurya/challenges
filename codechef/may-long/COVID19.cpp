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

int arr[8];
int infect[7];
int32_t main(){
	fastIO();
	/** code here */
	w(t){
		int n; cin>>n;
		for (int i = 0; i < n; ++i){
			cin>>arr[i];
		}
		// cout<<endl;
		// cout<<"=========="<<endl;
		vi zeros;
		for (int i = 1; i < n; ++i){
			if(arr[i] - arr[i-1] > 2){
				zeros.pb(i);
				// cout<<i<<" ";
			}
		}
		// cout<<endl;
		// cout<<"=========="<<endl;

		if(zeros.size() == 0){
			// cout<<"ds";
			cout<<n<<" "<<n<<endl;
			continue;
		}

		int mini = zeros[0];
		int maxi = zeros[0];
		int size = zeros.size();
		for (int i = 1; i < size; ++i){
			mini = min(mini, zeros[i]-zeros[i-1]);
			maxi = max(maxi, zeros[i]-zeros[i-1]);
		}

		mini = min(mini, n-zeros[size-1]);
		maxi = max(maxi, n-zeros[size-1]);
	


		cout<<mini<<" ";
		cout<<maxi<<endl;;
	}
	return 0;
}