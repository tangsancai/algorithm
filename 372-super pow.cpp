#include<iostream>
#include<vector>
using namespace std;
int mPow(int a, int k)  
{
	if(k ==0)
	{
		return 1;
	} 
	int ans = 1;  
 	for(int i = 1; i <= k; i++)
	{
 		ans = (ans*a) %1337; 
 	}  	 
   	return ans;  
}  
      
int superPow(int a, vector<int>& b) 
{
	if(b.empty())
	{
		return 1; 
	} 
  	a = a%1337;  
   	int lastBit = b.back();  
    b.pop_back();  
    return (mPow(superPow(a, b), 10) * mPow(a, lastBit))%1337;  
}
int main()
{
	int a=2;
	vector<int> b;
	b.push_back(3);
	cout<<superPow(a,b)<<endl;
}