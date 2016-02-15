#include "head.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
  	vector<vector<int>> ret;
	dfs(0, nums.size(), nums, ret);
	PrintVV(ret, "ret");
	return ret;      
    }

    void dfs(int pos, int n, vector<int> cur, vector<vector<int>> &ret){
	if(pos==n){
	    ret.push_back(cur);
	    return;
	}
	for(int i=pos; i<n; ++i){
	    swap(cur[pos], cur[i]);
	    dfs(pos+1, n, cur, ret);
	}
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution sol;
    sol.permute(nums);
    return 0;
}
