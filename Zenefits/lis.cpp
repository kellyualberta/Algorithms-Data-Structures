#include "head.h"

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    cin>>s;
    int N = stoi(s);
    vector<int> nums;
    while(cin>>s){
        nums.push_back(stoi(s));
    }
    cout<<N<<endl;
    PrintVector(nums,"nums");
    vector<int> dp(N, 1);
    for(int i=0; i<N; ++i){
        for(int j=0; j<i; ++j){
            if(nums[i]>nums[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    cout<<dp[N-1]<<endl;
    return 0;
}

