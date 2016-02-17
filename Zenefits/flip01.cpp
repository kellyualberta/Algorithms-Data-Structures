#include "head.h"

vector<int> flip(vector<int> &in){
    int sz = in.size();
    int i = 0;
    int j = 0;
    int m = 0;
    int M = 0;
    for(auto n:in){
	if(n==0){ 
	    m += 1;
	}else{
	    m -= 1;
	}
	M = max(M, m);
    }
}

int main(){
    return 0;
}
