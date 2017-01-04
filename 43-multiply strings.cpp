#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string multiply(string num1,string num2)
{
	string result="";
	int m=num1.size();
	int n=num2.size();
	vector<int> ans(m+n,0);
        
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans[i+j]+=(num1[i]-'0')*(num2[j]-'0');
   			ans[i+j+1]+=ans[i+j]/10;
      		ans[i+j]%=10;
        }
   	}
   	int i=m+n-1;
    while(i>0&&ans[i]==0) 
		i--;
    for(;i>=0;i--) 
		result+=to_string(ans[i]);
  	return result;
} 