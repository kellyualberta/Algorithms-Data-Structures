#include <cmath>
#include <limits.h>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm> 
#include <stdlib.h> 
#include <stack>
#include <map>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <iomanip> 
#include <cstring>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <functional>
#include <fstream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     void print(){
       ListNode *t = this;
       do{
         cout<<t->val<<"->";
	 t = t->next;
       }while(t!=NULL);
       cout<<endl;
     }
};

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


void PrintBit(long long v, string msg, int n){
  string s;
//  while(v){
  for(int j=0; j<n; ++j){
    int i = v&1;
    string ss = i==0?"0":"1";
    s = ss+s;
    v = v>>1;
  }
  cout<<msg<<": "<<s<<endl;
}

template<typename T>
void PrintStack(const stack<T> stk, string str){
  cout<<str<<":";
  stack<T> s = stk;
  deque<T> v;
  while(!s.empty()){
    v.push_front(s.top());
    s.pop();
  }
  for(auto it:v){
    cout<<it;
  }
  cout<<endl;
}



template<typename T>
void PrintQueue(const queue<T> q, string str){
  cout<<str<<":";
  queue<T> que = q;
  while(!que.empty()){
    cout<<que.front()<<" ";
    que.pop();
  }
  cout<<endl;
}

template<typename T>
void PrintArray(T A[], int n){
  for(int i=0; i<n; ++i){
    cout<<A[i]<<" ";
  }
  cout<<endl;
}

template<typename T>
void PrintSet(const unordered_set<T> v, string str){
  cout<<str<<":";
  for(typename unordered_set<T>::const_iterator it=v.begin(); it!=v.end(); ++it){
    cout<<*it<<" ";
  }
  cout<<endl;
}


template<typename T>
void PrintVector(const vector<T> v, string str){
  cout<<str<<":";
  for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it){
    cout<<setw(3)<<*it<<" ";
  }
  cout<<endl;
}

template<typename T>
void PrintVV(vector<vector<T>> vv,string msg){	
  cout<<msg<<":\n";
  int m = vv.size();
  for(int i=0; i<m; ++i){
//    if(!vv[i].empty()) 
	PrintVector(vv[i], "");
  }
}


template<typename T>
void PrintMap(map<T, int> m, string str){
  cout<<str<<"||";
  for(typename map<T, int>::iterator it=m.begin(); it!=m.end(); ++it){
    cout<<it->first<<":"<<it->second<<"   ";
  }
  cout<<endl;
}

template<typename T>
void PrintUMap(unordered_map<T, int> m, string str){
  cout<<str<<"||";
  for(typename unordered_map<T, int>::iterator it=m.begin(); it!=m.end(); ++it){
    cout<<it->first<<":"<<it->second<<"   ";
  }
  cout<<endl;
}

ListNode * createList(int A[],int n){
  ListNode * head = new ListNode(A[0]);
  ListNode * p = head;
  for(int i=1; i<n; ++i){
    ListNode * node = new ListNode(A[i]);
    p->next = node;
    p = node;
  }
  return head;
}

void
PrintListNode(ListNode * head){
  while(head!=NULL){
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<endl;
}

//generate a fraction between [0,1]
double 
generateRandomFraction(){
  double tmp = rand()/(double)RAND_MAX;
  return tmp;
}


vector<int> kmpTable(string s){
    int n = s.size();
//    T[i]:length of the longest proper prefix ending at T[i-1]
    vector<int> T(n, 0);
    T[0] = -1;
    T[1] = 0;
    int p = 2, c = 0;
    while(p<n){
      if(s[p-1]==s[c]){
        T[p++] = ++c;
      }else if(c>0){
        c = T[c];
      }else{
        T[p++] = 0;
      }
    }
    return T;
}

int kmp(string S, string W){
    vector<int> T = kmpTable(W);
    int n = S.size();
    int i=0, m=0;
    while(i+m<n){
      if(S[m+i]==W[i]){
        if(i==W.size()-1) return m;
        else i++;
      }else{
        if(T[i]>=0){
          m = m+i-T[i];
          i = T[i];
        }else{
          m++;
          i=0;
        }
      }
    }
}

