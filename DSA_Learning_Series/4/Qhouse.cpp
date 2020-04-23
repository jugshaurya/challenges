// https://www.codechef.com/LRNDSA04/problems/QHOUSE

#include<bits/stdc++.h>
using namespace std;

// finding last "YES" always
int binarySearch(int l, int r, int val, bool yflag){
	int ans = 0;
	while(l<=r){
		int mid = (l+r)/2;
		if(yflag){
			cout<<"? "<<mid<<" "<<val<<endl;
		}else{
			cout<<"? "<<val<<" "<<mid<<endl;
		}
		string s;
		cin>>s;
		if(s == "YES"){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// observations : 
	// figure is symmetric around y axis
	// All vertices of the square and the triangle have integer coordinates 
	// Both the square and the triangle are non-degenerate, i.e their areas are positive, and not zero.

	// 1. first find out the right most square point in log(1000) steps (x',0)
	int sq_side = 2*binarySearch(0, 1000, 0, 1);
	int area = sq_side*sq_side;
	int height = binarySearch(0, 1000, 0, 0) - sq_side;
	int base = binarySearch(0, 1000, sq_side, 1);  
	area += (base*height); 
	cout<<"! "<<area<<endl;
	return 0;
}