#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define endl            "\n"
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
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void fastIO(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	#ifndef ONLINE_JUDGE	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

bool isMultipleThree(int k, int d0, int d1){
	
	int firstTwo = (d0+d1);
	if(k==2){
		return firstTwo%3 == 0;
	}

	int repeatedBoxes = (k-3)/4;
	int last_remaining_count = k-3-(repeatedBoxes*4);
	int repeated_sequence_sum = (2*(firstTwo%10))%10 + 
								(4*(firstTwo%10))%10 +
								(8*(firstTwo%10))%10 +
								(6*(firstTwo%10))%10;

	int last_remaining_count_sum = 0;
	if(last_remaining_count==1)
		last_remaining_count_sum += (2*(firstTwo%10))%10;
	if(last_remaining_count==2)
		last_remaining_count_sum += (2*(firstTwo%10))%10 + (4*(firstTwo%10))%10;
	if(last_remaining_count==3)
		last_remaining_count_sum += (2*(firstTwo%10))%10 + (4*(firstTwo%10))%10 + (8*(firstTwo%10))%10 ;
	int total_sum = firstTwo + firstTwo%10 + repeatedBoxes*repeated_sequence_sum + last_remaining_count_sum;
	return total_sum %3 == 0;
}

int32_t main(){
	fastIO();
	/** code here */
	w(t){
		int k, d0, d1;
		cin >> k >> d0 >> d1;

		if(isMultipleThree(k,d0,d1)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}