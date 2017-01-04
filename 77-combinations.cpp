#include<iostream>
#include<vector>
using namespace std;
vector< vector<int> > combine(int n, int k)
{
	vector< vector<int> > res;
 	if(k==1)
 	{
	 	for(int i=1;i<=n;++i) 
		 	res.push_back({i});
    	return res;
   	} 
   	else if(k==n) 
   	{
	   	res.resize(1);
	   	for(int i=1;i<=n;++i)
		   	res[0].push_back(i);
      	return res;
    }
    res=combine(n-1,k);
    auto tmp=combine(n-1,k-1);
    for(auto& x:tmp) 
		x.push_back(n);
    res.insert(res.end(),tmp.begin(),tmp.end());
    return res;
}