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

float squareRoot(int number, int precision) { 
    int start = 0, end = number; 
    int mid; 
    float ans; 
    while (start <= end) { 
        mid = (start + end) / 2; 
        if (mid * mid == number) { 
            ans = mid; 
            break; 
        } 
  
        if (mid * mid < number) { 
            start = mid + 1; 
            ans = mid; 
        } 
        else { 
            end = mid - 1; 
        } 
    } 
  
    float increment = 0.1; 
    for (int i = 0; i < precision; i++) { 
        while (ans * ans <= number) { 
            ans += increment; 
        } 
        ans = ans - increment; 
        increment = increment / 10; 
    } 
    return ans; 
} 

map<int, bool> m;
int32_t main() {
	const int max = 10001;

	fastIO();
	/** code here */
	vi psq;
	for (int i = 1; i <= max; ++i){
		psq.pb(i*i);
	}

	w(t){
		int n; cin>>n;
		bool gotcha = false;
		for (int i = 1; i <= max; ++i){
			int lhs = n + psq[i-1];
			int log_lhs = (int)(squareRoot(lhs,2));
			if(log_lhs*log_lhs == lhs){
				cout<<psq[i-1]<<endl;
				gotcha = true;
				break;
			} 
		}
		
		if(!gotcha)	cout<<-1<<endl;
	}
	return 0;
}
