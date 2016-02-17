#include "head.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
 	int n = nums.size();
	vector<int> dp(n, 1);
	for(int i=1; i<n; ++i){
	    for(int j=0; j<i; ++j){
		if(nums[i]>nums[j]){
		    dp[i] = max(dp[i], dp[j]+1);
		    if(dp[i]>=3) return true;
		}
	    }
	}       
	return false;
    }

    bool increasingTriplet1(vector<int>& nums) {
        vector<int> dp;
        for(auto n:nums){
            if(dp.empty()||n>dp.back()){
                dp.push_back(n);
                if(dp.size()>=3) return true;
            }else{
                int l = 0, r = dp.size()-1;
                while(l<=r){
                    int m = (l+r)/2;
                    if((m==0||n>dp[m-1])&&n<=dp[m]){
                        dp[m]=n;
                        break;
                    }else if(n>dp[m]){
                        l = m+1;
                    }else{
                        r = m-1;
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    vector<int> nums = {2,5,3,4,5};
    Solution sol;
    cout<<sol.increasingTriplet1(nums)<<endl;
    return 0;
}
