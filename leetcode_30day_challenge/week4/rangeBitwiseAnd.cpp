
// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.


class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = m;
        for (int i = m+1; i <= n; ++i){
       		ans = ans & i;
        }

        return ans;
    }
};

0000

//  find the first set bit of m starting from left let it be (i)

0001
0010

0011
0100

0101
0110

0111

1000
1001

1010
1011


  1000 8 
& 1101 9
  -----
  1000 8
  -----


  1110 14
& 1111 15
  ----
  1110 14
  ----

// observation 
// n&n-1 == n if n is odd 
// for every number of power 2 there will be only 1 set bit
  // means if [m,n] contains more than a single value with power of 2 like(8, 16) ans of that RangeAnd is 0. 
  // if only exactly a single value with power of 2 is in and that power is not in either end then ans is 0. because values lesser than that 2power contains zero at the ith nit
  	// then check for the position of set bit in that 2th power.

  // if no power of 2 is in the range
  	// then ====================
