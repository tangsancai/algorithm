#include<vector>
#include<iostream>
using namespace std;

class MinStack {
public:
	vector<int> v; 
	bool flag;
	int minn;
	
    MinStack() {
        flag=true;
        minn=INT_MAX;
    }
    
    void push(int x) {
    	v.push_back(x);
		if(v.back()<minn)
			minn=v.back();
    }
    
    void pop() {
    	if(v.back()==minn)
    		flag=false;
        v.pop_back();
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
    	if(!flag)
		{
			minn=INT_MAX;
			for(int i=0;i<v.size();++i)
        		if(minn>v[i])
        			minn=v[i];
			flag=true;
		} 
   		return minn;
    }
};