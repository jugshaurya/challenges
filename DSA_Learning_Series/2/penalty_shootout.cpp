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
	/** code here */
	w(t){
		int n; cin>>n;
		string s;
		cin>>s;
		int a_cs = 0;
		int a_rs = n; // rs - remaining shots
		int b_cs = 0; // cs - current score
		int b_rs = n;
		bool gotcha = false; // to state the draw

		//  if i am B
		// c_goals(A) > c_goals(B) + r_goals(B) , i loose
		// c_goals(B) > c_goals(A) + r_goals(A) , i win
		// else i can't give the verdict.

		for (int i = 0; i < 2*n; ++i){
			int value = s[i] - '0';
			if(i&1) {
				// B team chance
				b_cs += value;
				b_rs -= 1;
				if(a_cs > b_cs + b_rs || b_cs > a_cs + a_rs){
					cout<<i+1<<endl;
					gotcha = true;
					break;
				}
			}else{
				// A team chance
				a_cs += value;
				a_rs -= 1;
				if(b_cs > a_cs + a_rs || a_cs > b_cs + b_rs){
					cout<<i+1<<endl;
					gotcha = true;
					break;
				}
			}
		}

		if(!gotcha){
			cout<<2*n<<endl;
		}
	}
	return 0;
}