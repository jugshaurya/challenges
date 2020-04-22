/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
		vector<int> dim = binaryMatrix.dimensions();
		int m = dim[0];
		int n = dim[1];

		int leftMostColumn = n;
        int ans = 1e9;
		for (int i = 0; i < m; ++i){
			// row is sorted we need to find the index of first 1 in this row
			int start = 0;
			int end = n-1;
			while(start <= end){
				int mid = (start+end)/2;
				if(binaryMatrix.get(i,mid) == 1){
					ans = mid;
					end = mid - 1; 
				}else{
					start = mid + 1;
				}	
			}
			leftMostColumn = min(leftMostColumn, ans);
		}		
		if(ans == 1e9) return -1;
        return leftMostColumn;
	}
};