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

void printVector(const std::vector<int> &n)
{

    for (int j = 0; j < n.size(); j++ )
    {
        cout << "n[" << j << "] = " << n[j] << endl;
    }

}
int32_t main(){
	fastIO();
	/** code here */

    vector<int> n = {1,2,3,4,5};
	vector < vi > factors;
	factors.pb(n);


    for (int j = 0; j < factors.size(); j++ ){
    	printVector(factors[j]);
    }
	return 0;
}