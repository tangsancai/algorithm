#include<iostream>
#include<vector>
#include<set>
using namespace std;

int maximumGap(vector<int>& nums)//投机取巧了，23ms 
{
	if(nums.size()<2)
		return 0;
	set<int> s;
	for(int i=0;i<nums.size();++i)
		s.insert(nums[i]);
	int pre=*(s.begin());
	int maxx=INT_MIN;
	for(set<int>::iterator it=s.begin();it!=s.end();++it)
	{
		int tmp=*it-pre;
		if(tmp>maxx)
			maxx=tmp;
		pre=*it;
	}
	return maxx;
}
//桶排序，最大gap只可能出现在相邻桶之间，不可能出现在桶内（源于桶大小的选择） 。48ms 
struct Bucket {  
    int local_min;  
    int local_max;  
    int local_volumn;  
    Bucket():local_volumn(0){};  
};  
int maximumGap(vector<int> &num) 
{  
	if (num.size() < 2) 
		return 0;  
 	if (num.size() == 2) 
	 	return num[0] - num[1] > 0 ? num[0] - num[1] : num[1] - num[0];  
   	int min = INT_MAX;  
    int max = INT_MIN;  
    int max_gap = 0;  
    for (int i = 0; i < num.size(); ++i)
	{  
 		if (num[i] < min) 
		 	min = num[i];  
    	if (num[i] > max) 
			max = num[i];  
   	}
   	int bucket_length = (max - min) / (num.size() - 1) + 1;//！！！！！桶大小选择，至关重要  
    int bucket_count = (max - min) / bucket_length + 1;  
    vector<Bucket> bucket(bucket_count, Bucket());  
    for (int i = 0; i < num.size(); ++i)
	{
		int index = (num[i] - min) / bucket_length;  
  		if (bucket[index].local_volumn == 0) //NOTE1: 如果桶内最多只有一个元素，那么max 和 min都赋值为这个元素。  
            bucket[index].local_max = bucket[index].local_min = num[i];  
    	else if (num[i] > bucket[index].local_max)  
     		bucket[index].local_max = num[i];  
       	else if (num[i] < bucket[index].local_min)  
        	bucket[index].local_min = num[i];  
        bucket[index].local_volumn++;  
    }
	int previous = 0; //NOTE2: 用previous来跳过空桶,第0个桶必然不是空桶，所以previous可以从0开始取值。  
 	for (int i = 1; i < bucket.size(); ++i)
 	{
	 	if (bucket[i].local_volumn == 0) 
		 	continue;  
    	if (bucket[i].local_min  - bucket[previous].local_max > max_gap)  
     		max_gap = bucket[i].local_min  - bucket[previous].local_max;  
       	previous = i;  
   	}  
    return max_gap;  
}  