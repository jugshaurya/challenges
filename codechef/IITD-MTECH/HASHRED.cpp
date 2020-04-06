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

int hashValue(string &s){
	int result  =0 ;
	for (int i = 0; i < s.length(); ++i){
		result += s[i]-'a';
	}
	return result;
}

string next(string s){

	int last_decreaseable = -1;
	int last_increaseable = -1;
	int n = s.length();
	if(s[n-1] == 'z'){
		last_decreaseable = n-1;
	}else if(s[n-1]=='a'){
		last_increaseable = n-1;
	}else{
		last_increaseable = last_decreaseable = n-1;
	}

	
	for (int i = s.length()-2; i >=0; i--){
		if(s[i] == 'z'){
			last_decreaseable = i;
		}else if(s[i]=='a'){
			last_increaseable = i;
		}else{
			if(last_decreaseable != -1){
				s[i] += 1;
				s[last_decreaseable] -= 1;
				break;
			}

			if(last_increaseable!=-1){
				s[i] -= 1;
				s[last_increaseable] += 1;
				break;	
			}
		}
	}

	return s;
}

int32_t main(){
	fastIO();
	/** code here */
	w(t){
		string s;
		cin>>s;
		cout<<hashValue(s)<<" ";
		cout<<next(s)<<endl;
	}
	return 0;
}