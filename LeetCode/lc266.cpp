#include "head.h"

class Solution {
public:
    bool canPermutePalindrome(string s) {
 	map<char, int> hash;
	int odd = 0;
	for(char c:s){
	    hash[c]++;
	    if(hash[c]%2==1){
		odd++;
	    }else{
		odd--;
	    }
	}       
	return odd<2;
    }
};

int main(){
    return 0;
}
