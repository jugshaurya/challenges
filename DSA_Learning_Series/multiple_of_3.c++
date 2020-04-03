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

bool doit(int k, int d0, int d1){
	int firstTwo = (d0+d1)%3;
	if(k==2){
		return firstTwo == 0;
	}

	int a = d0;
	int b = d1;
	int c = a+b;
	int x = 2;
	int last_before_2468box = c;
	while(c!=2){
		x += 1;
		a = b;
		b = c;
		last_before_2468box += c;
		if(c==5) return false;
		c = (2*b)%10;
	}

	int initial_type = last_before_2468box%3 ;
	int which_repeted_box_of_2486 = ((k-x-1)/4)3%;
	int last_subset_length = k -x - 4 * ((k-x)/4) ;


	int sum_type = (2*which_repeted_box_of_2486+2+initial_type)%3; // 3n + sum_type 
	cout<<firstTwo<<last_before_2468box%3<<x<<which_repeted_box_of_2486<<(sum_type%3)<<last_subset_length;
	
	if(sum_type==0){
		if(last_subset_length==0 || last_subset_length==3)return true;
		else return false;

	}else if(sum_type==1){
		if(last_subset_length==2)return true;
		return false;
	}else{
		if(last_subset_length==1) return true;
		return false;
	}
}

int32_t main(){
	fastIO();
	/** code here */
	w(t){
		int k, d0, d1;
		cin >> k >> d0 >> d1;

		if(doit(k,d0,d1)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}