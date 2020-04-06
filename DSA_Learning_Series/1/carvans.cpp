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
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define endl			"\n"
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
	int arr[10000]={0};
	w(x){
		int activities;
		string origin;
		cin >> activities >> origin;
		string type;
		int rank;
		int result = 0;
		for (int i = 0; i < activities; ++i){
			cin>>type;
			if(type=="CONTEST_WON"){
				cin>>rank;
				if(rank<=20){
					result += 300 + 20 - rank;
				}else{
					result += 300;
				}
			}else if (type=="BUG_FOUND") {
				cin>>rank;
				result +=rank;
			}else{
				if(type=="TOP_CONTRIBUTOR"){
					result += 300;
				}else{
					// CONTEST_HOSTED
					result += 50;
				}
			}
		}
		if(origin =="INDIAN"){
			cout<<result/200<<endl;
		}else
			cout<<result/400<<endl;
	}
	return 0;
}