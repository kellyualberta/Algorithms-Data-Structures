#include "head.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
 	vector<vector<int>> ret;
	sort(nums.begin(), nums.end());
	dfs(0, nums.size(), nums, ret);
	PrintVV(ret, "ret");
	return ret;       
    }
    void dfs(int pos, int n, vector<int> cur, vector<vector<int>> &ret){
	if(pos==n){
	    ret.push_back(cur);
	}else{
	    for(int i=pos; i<n; ++i){
		if(i>pos && cur[i]==cur[pos]){
		    continue;
		}else{
		    swap(cur[pos], cur[i]);
		    dfs(pos+1, n, cur, ret);
	 	}
	    }
	}
    }
};

int main(){
    vector<int> nums = {1,1,2};
    Solution sol;
    sol.permuteUnique(nums);
    return 0;
}
