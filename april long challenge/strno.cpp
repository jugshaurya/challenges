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
	freopen("output.txt", "w", stderr);
	#endif
}


const int N = 1e6;
int primes[N];

void SieveOfEratosthenes() { 
    bool prime[N]; 
    for (int i = 2; i < N; ++i){
    	prime[i]  = true;
	} 
    for (int p=2; p<N; p++) { 
        if (prime[p]) {
            for (int i=p*p; i<N; i += p) 
                prime[i] = false; 
        } 
    } 

    int j=0;
    for (int i = 2; i < N; ++i){
    	if(prime[i]){
    		primes[j++] = i;
    	}
    }    
}

int factors_count(int n){
	int count = 0;
	for (int i = 0; i*i < N; ++i){
		int p = primes[i];
		if(n>1){
			while(true){
				if(n%p==0){
					n = n/p;
					// cout<<p<<" ";
					count +=1;
				}else{
					break;
				}
			}
		}else{
			break;
		}
	}
	// culprit - gotcha
	if(n>2){
		count++;
	}
	return count;
}	

int32_t main() {
	fastIO();
	/** code here */
	SieveOfEratosthenes();
	w(t){
		// algo 
		// find number of factors of X if that is less than K 
		// return 0 else 1
		int x,k; cin>>x>>k;
		if(k==1){
			if(x>=2){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
			continue;
		}
		
		int number_of_factors = factors_count(x);
		if(number_of_factors < k )
			cout<<0<<endl;
		else
			cout<<1<<endl;
	}	
	return 0;
}