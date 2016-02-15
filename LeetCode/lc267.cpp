#include "head.h"

class Solution {
public:
    vector<string> generatePalindromes(string s) {
 	map<char, int> hash;
	int odd = 0;
	char odd_c;
	for(char c:s){
	    hash[c]++;
	    if(hash[c]%2){
		odd++;
	    }else{
		odd--;
	    }
	}   
	vector<string> ret;
	if(odd>=2){
	    return ret;
	}
	if(s.size()==1){
	    ret.push_back(s);
	    return ret;
	}

	string half;
	for(auto h:hash){
	    half += string(h.second/2, h.first);
	    if(h.second%2){
		odd_c = h.first;
	    }
	}
	cout<<half<<endl;	

	sort(half.begin(), half.end());
	vector<string> halfs;
	dfs(0, half.size(), half, halfs);
	PrintVector(halfs, "halfs");
	for(auto h:halfs){	
	    string r = h;
	    if(odd){
		h += odd_c;
	    }
	    cout<<h<<endl;
	    reverse(r.begin(), r.end());
	    ret.push_back(h+r);
	}
	return ret;
    }
    void dfs(int pos, int n, string cur, vector<string> &ret){
	if(pos==n){
	    if(cur.size()) ret.push_back(cur);
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
    Solution sol;
    sol.generatePalindromes("ivicc");
    return 0;
}
