// 2^a[i] time and space complexity
class Solution {
public:

	bool helper(vector<int>& nums, int i, int n){
		if(i>n){
			return false;
		}

		if(i==n){
			return true;
		}

    	int firstEle = nums[i];
        if(firstEle == 0) return false;
        int ans = false;
        for (int val = 1; val <= firstEle; ++val){
        	ans = ans || helper(nums, i+val, n);
        }

        return ans;
	}

    bool canJump(vector<int>& nums) {
    	return helper(nums, 0, nums.size()-1);
    }
};


// 2^a[i] time and space complexity
class Solution {

public:

	bool helper(vector<int>& nums, int i, int n){
		if(i>n){
			return false;
		}

		if(i==n){
			return true;
		}

    	int firstEle = nums[i];
        if(firstEle == 0) return false;
        int ans = false;
        for (int val = 1; val <= firstEle; ++val){
        	ans = ans || helper(nums, i+val, n);
        }

        return ans;
	}


	bool helperdp(vector<int>& nums, int i, int n, int* dp){

		if(i>n){
			return 0;
		}

		if(i==n){
			dp[n] = 1;
			return dp[n];
		}

		if(dp[i] !=-1){
			return dp[i];
		}

    	int firstEle = nums[i];
        if(firstEle == 0) return 0;
        dp[i] = 0;
        for (int val = 1; val <= firstEle; ++val){
        	if(helper(nums, i+val, n) == 1){
        		dp[i] = 1;
        		break;
        	}
        }

        return dp[n];
	}

    bool canJump(vector<int>& nums) {
    	int n = nums.size();
    	int* dp = new int[n+1];
    	memset(dp, -1, n+1);
    	return helperdp(nums, 1, n, dp);
    }
};