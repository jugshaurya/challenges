class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	vector<int> presum;
    	presum.push_back(0);
    	for (int i = 1; i <= nums.size(); ++i){
    		presum.push_back(presum[i-1]+nums[i-1]);
    	}

    	map<int, int > m;
    	for(int x : presum){
    		if(m.count(x)){
	    		m[x]++;
    		}else{
    			m[x] = 1;
    		}
    	}

    	int total = 0;

    	for(int x: presum){
            m[x]--;
    		total += m[x+k];
    	}

    	return total;
    }
};



//   1 2 4 -1 -3 4 -4 3 -2 1 5 -1  1  5 -> 6
// 0 1 3 7  6  4 8  4 7  5 6 11 10 11 16


// total = 0
// for eveyr value (ai) 
// 	find if k+ai is in map if yes then how many times (let ti)
// 		total ways in this case += ti

// 	 [1,1,1,1 ,2 ,-1 -1] -> k=2 => 3
// 	presum => 0 1 2 3 4 6 5 4
// 	presum+k => 2 3 4 5 6 8 7
// 	freq[presum+k] in presum map => 1 1 2 1 1 0 0
// 	1 
// 	1
// 	1