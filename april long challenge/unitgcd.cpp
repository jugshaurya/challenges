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
const int sqrtN = sqrt(N);
vector<int> factors[N];

void sieveToGetFactorsArray(){

	for (int i = 2; i < sqrtN; i++){
		if(factors[i].size() == 0){
			for (int j = i; j < N; j+=i){
				factors[j].pb(i);
			}
		}
	}
}


int32_t main(){
	fastIO();
	for (int i = 0; i < sqrtN; ++i){
		vector<int> v;
		factors[i] = v;
	}
	sieveToGetFactorsArray();


	w(t){
		int n; cin>>n;
		if(n==1){
			cout<<1<<endl;
			cout<<1<<" "<<1<<endl;
			continue;
		}

		int done[N];
		memset(done, 0, N);
		set<int> setArray[n/2];
		vector< vector<int> > result;
		int idx = -1;
		
		for (int i = 2; i < n+1; i+=2){
			idx+=1;
			if(i==2){
				done[1] = done[2] = 1;
				vector<int> v;
				v.pb(1);
				v.pb(2);
				result.pb(v);
				set<int> s;
				s.insert(2);
				setArray[idx] = s;
			}else{
				done[i] = 1;
				vector<int> v;
				v.pb(i);
				result.pb(v);
				set<int> s;
				for (auto x: factors[i]){
					s.insert(x);
				}
				setArray[idx] = s;
			}
		}

		for (int i = 3; i < n+1; i+=2){
			idx = 0;
			int j = i;
			while(j<n+1){
				if(done[j]==0){
					set<int> j_factor_set;
					for(auto x : factors[j]){
						j_factor_set.insert(x);
					}
					set<int> not_allowed_set = setArray[idx];
					vector<int> aloha(j_factor_set.size() + not_allowed_set.size());
					vector<int>::iterator it, st;
					it = set_intersection(j_factor_set.begin(), 
											j_factor_set.end(), 
											not_allowed_set.begin(), 
											not_allowed_set.end(), 
											aloha.begin()
											);
					int size = 0;
					for (st = aloha.begin(); st != it; ++st) 
						size += 1;
					int product = 1;
					set <int>:: iterator itr = j_factor_set.begin(); 
					for (; itr != j_factor_set.end(); ++itr){
						product *= (*itr);
					}
					// cout<<product<<" afagdg"<< j<< product<<endl;;
					// auto size = __gcd(j, product);
					if(size == 0){
						result[idx].pb(j);
						done[j] = 1;
						idx+=1;
						for (auto ele : j_factor_set){
							setArray[idx-1].insert(ele);
						}
					}else{
						// i can not put in here
                        if(idx == 0){
                            done[j] = 1;
                            setArray[idx].insert(j);
                            result[0].pb(j);
                            idx += 1;
                        }else{
                            idx += 1;
                            continue;
                        }
					}
				}
			j+=i;
			}
		}

		cout<<n/2<<endl;
		for (int i = 0; i < result.size(); ++i){
			cout<<result[i].size()<<" ";
			for(auto ell : result[i]){
				cout<<ell<<" ";
			}
			cout<<endl;
		}
	}
}
