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
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vector<int>,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007 // 1e9+7
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)	type *arr=new type[n];
#define w(t)            int t; cin>>t; while(t--)
#define pw(b,p)         pow(b,p) + 0.1
#define endl			"\n"

void fastIO(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// for kickstart comment last four lines
	#ifndef ONLINE_JUDGE	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("output.txt", "w", stderr);
	#endif
}

const int N = 1e6+1;

int32_t main(){
	fastIO();
	w(t){
		int n; cin>>n;
		if(n==1){
			cout<<1<<endl;
			cout<<1<<" "<<1<<endl;
			continue;
		}

		if(n==2){
			cout<<1<<endl;
			cout<<2<<" "<<1<<" "<< 2 <<endl;
			continue;
			
		}

		cout<<n/2<<endl;
		cout<<3<<" "<<1<<" "<< 2<<" " <<3<<endl;
		for (int i = 4; i < n;){
			cout<<2<<" "<<i<<" "<<i+1<<endl;
			i+=2;
		}
		if(n%2==0){
			cout<<1<<" "<<n<<endl;
		}
	}

}
