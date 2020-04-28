class FirstUnique {
public:
	vector<int> v;
	map<int, int> m;
	FirstUnique(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i){
			if(m.count(nums[i]) == 0) {
				m[nums[i]] = 1;
				v.push_back(nums[i]);
			}else {
				m[nums[i]] +=1;
			}
		}
    }
    
    int showFirstUnique() {
    	for (int i = 0; i < v.size(); ++i){
    		if(m[v[i]]==1){
    			return v[i];
    		}
    	}
    	return -1;
    }
    
    void add(int value) {
    	if(m.count(value)== 0){
    		v.push_back(value);
    		m[value] = 1;
    	}else{
    		m[value] +=1;
    	}
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */