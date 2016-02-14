/*
http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
*/

#include "head.h"

class BIT{
    vector<int> bitree;
    int sz;//size of binary indexed tree
public:
    BIT(vector<int> array){
	sz = array.size()+1;
	bitree.resize(sz, 0);
	for(int i=1; i<=sz; ++i){
	    update(i, array[i-1]);
	}
	PrintVector(bitree, "bitree");
    }

    //id is 1-based 
    void update(int id, int val){
	while(id<=sz){
	    bitree[id] += val;
	    id += (-id&id);
	}
    }

    //id is 1-based
    int getSum(int id){
	int s = 0;
	while(id>0){
	    s += bitree[id];
	    id -= (-id&id);
	}
	return s;
    }
};

int main(){
    vector<int> array = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    BIT bit(array);
    cout<<"the sum of the first 2 elements is : "<<bit.getSum(2)<<endl;
    cout<<"the sum of the first 5 elements is : "<<bit.getSum(5)<<endl;
    cout<<"increase the 3nd element of array by 3\n";
    bit.update(3, 3);
    cout<<"the sum of the first 2 elements is : "<<bit.getSum(2)<<endl;
    cout<<"the sum of the first 5 elements is : "<<bit.getSum(5)<<endl;
    return 0;
}
