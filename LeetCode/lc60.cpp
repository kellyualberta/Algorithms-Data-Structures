#include "head.h"

class Solution {
    int factorial(int n){
	if(n==0) return 1;
	return n*factorial(n-1);
    }
public:
    string getPermutation(int n, int k) {
	vector<int> vec(n);
	for(int i=0; i<n; ++i){
	    vec[i] = i+1;	    
	} 	       
	string ret;
	while(ret.size()<n){
	    int t = n - ret.size();
	    int group_c = factorial(t-1);
	    int group_id = (k-1)%group_c;
	    k -= group_id*group_c;
	    ret += to_string(vec[group_id]);
	    vec.erase(vec.begin()+group_id);
	}
	cout<<"ret is "<<ret<<endl;
	return ret;
    }
};

int main(){
    Solution sol;
    sol.getPermutation(4, 2);
    return 0;
}
