#include<iostream>
#include<vector>
#include<set>
using namespace std;

int maximumGap(vector<int>& nums)//Ͷ��ȡ���ˣ�23ms 
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
//Ͱ�������gapֻ���ܳ���������Ͱ֮�䣬�����ܳ�����Ͱ�ڣ�Դ��Ͱ��С��ѡ�� ��48ms 
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
   	int bucket_length = (max - min) / (num.size() - 1) + 1;//����������Ͱ��Сѡ��������Ҫ  
    int bucket_count = (max - min) / bucket_length + 1;  
    vector<Bucket> bucket(bucket_count, Bucket());  
    for (int i = 0; i < num.size(); ++i)
	{
		int index = (num[i] - min) / bucket_length;  
  		if (bucket[index].local_volumn == 0) //NOTE1: ���Ͱ�����ֻ��һ��Ԫ�أ���ômax �� min����ֵΪ���Ԫ�ء�  
            bucket[index].local_max = bucket[index].local_min = num[i];  
    	else if (num[i] > bucket[index].local_max)  
     		bucket[index].local_max = num[i];  
       	else if (num[i] < bucket[index].local_min)  
        	bucket[index].local_min = num[i];  
        bucket[index].local_volumn++;  
    }
	int previous = 0; //NOTE2: ��previous��������Ͱ,��0��Ͱ��Ȼ���ǿ�Ͱ������previous���Դ�0��ʼȡֵ��  
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