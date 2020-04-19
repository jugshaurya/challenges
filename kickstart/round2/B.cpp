// A.cpp

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
	#ifndef ONLINE_JUDGE	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

bool alpha(int* arr, int n, int mid, int d){
	bool possible = true;
	int start = 0;
	for (int i = 0; i < n; ++i){
		for(int j = 1; j < d; ++j){
			int ele = arr[i]*j;
			if(ele >= mid and ele >= start){
				if(ele>=mid){
					if(ele < start or ele>d){
						return false; 
					}
				}
				start = ele;
				break;
			} 
		}
	}

	return true;
}

bool alpha2(int* arr, int n, int mid, int d){
	bool possible = true;
	int start = 0;
	for (int i = 0; i < n; ++i){
		int m = max(ceil(mid*(1.0)/arr[i]), ceil(start*(1.0)/arr[i]) );
		int ele = arr[i]*m;
		if(ele >=start and ele<=d){
			start = ele;
			continue;
		}else{

			return false;
		}
		start = ele;
	}

	return true;
}


int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	// Comment out for kickstart
// 	fastIO();
	/** code here */
	int t;
    cin>>t;
    
    int tc = t;
    while (t--){


    	int n,d;
    	cin>>n>>d;
    	mk(arr,n,int);
    	for (int i = 0; i < n; ++i){
    		cin>>arr[i];
    	}

    	int left = 1;
    	int right = d;
    	int ans = 0;

    	while(left<=right){
    		int mid = (left+right)/2;
    		bool result = alpha2(arr,n,mid,d);
    		if(result){
    			ans = mid;
    			left = mid + 1; 
    		}else{
    			right = mid -1;
    		}
    	}

        cout<<"Case #"<<tc-t<<": "<<ans<<endl;
    }
	return 0;
}