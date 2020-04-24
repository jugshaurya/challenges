
// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
#include<bits/stdc++.h>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    }
};

// observation 
// n&n-1 == n if n is odd 

// check for how many power of 2 are there
// #power of 2 = ceil(log2(n)) - floor(log2(m)) + 1


  //   	if(no_of_2_powers >=2){
		// // means if [m,n] contains more than a single value with power of 2 like(8, 16) ans of that RangeAnd is 0. 
  //   		return 0;
  //   	}
  // if only exactly a single value with power of 2 is in and that power is neither m nor n, then ans is 0. because values lesser than that 2power contains zero at the ith nit
  	// but if it is m or n. then check in next case for [m+1,n] or [m,n-1]

  // if no power of 2 is in the range
  	// then ans is 1<<floor(log(m))



// 1001
// 1010
// 1011
// 1100
// 1101
// 1110
// 1111
// -----
// 1000 -> 1<<floor(log(m))  + 1<<floor(...)
// -----


    	// [2,3] 1, 2-1
    	// [3,4] 1, 2-1
    	// [4,5] 1, 3-2
    	// [3,5] 1, 3-1
    	// [1,2,3,4,5] 2
    	// [2,3,4,5] 2

