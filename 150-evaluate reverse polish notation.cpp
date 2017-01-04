#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int evalRPN(vector<string>& tokens)
{
	stack<int> d;
	int len=tokens.size();
	for(int i=0;i<len;++i)
	{
		if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
		{
			int a=d.top();
			d.pop();
			int b=d.top();
			d.pop();
			switch(tokens[i][0])
			{
				case '+':	d.push(b+a);
							break;
				case '-':	d.push(b-a);
							break;
				case '*':	d.push(b*a);
							break;
				case '/':	d.push(b/a);
							break;			
			}
		} 
		else
		{
			int sum=0;
			int lens=tokens[i].size();
			int jj=0;
			bool msign=false;
			if(tokens[i][0]=='-')
			{
				jj=1;
				msign=true;
			}
			for(int j=jj;j<lens;++j)
				sum=sum*10+tokens[i][j]-'0';
			sum=msign?-sum:sum;
			d.push(sum);
		}
	}
	return d.top();
}

int main()
{
	vector<string> v;
	v.push_back("3");
	v.push_back("-4");
	v.push_back("+");
	cout<<evalRPN(v)<<endl;
}