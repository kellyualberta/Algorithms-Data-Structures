#include "head.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
 	int n = nums.size();
	if(n<2) return;

	int i = n-2;
	while(i>=0 && nums[i]>=nums[i+1]){
	    --i;
	}      
	if(i<0){
	    sort(nums.begin(), nums.end());
	}else{
	    int k = -1;
	    for(int j=n-1; j>i; --j){
		if(nums[j]>nums[i] && (k<0 || nums[j]<nums[k])){
		    k = j;
		}
	    }
	    swap(nums[i], nums[k]);
	    sort(nums.begin()+i+1, nums.end());
	}
    }
};

int main(){
    vector<int> nums = {3,5,7,6,4};
    Solution sol;
    sol.nextPermutation(nums);
    PrintVector(nums, "nums");
    return 0;
}
