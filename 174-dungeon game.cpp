#include<iostream>
#include<vector>
using namespace std;

int calculateMinimumHP(vector< vector<int> >& dungeon)
{
	if(dungeon.empty()||dungeon[0].empty())
 		return 1;
   	int m=dungeon.size();
    int n=dungeon[0].size();
    vector<vector<int> > dp(m,vector<int>(n,0));
    for(int i=m-1;i>=0;--i)
		for(int j=n-1;j>=0;--j)
  		{
  			if(i==m-1&&j==n-1)
			  	dp[i][j]=max(1,1-dungeon[i][j]);
      		else if(i==m-1)
                dp[i][j]=max(1,dp[i][j+1]-dungeon[i][j]);
            else if(j==n-1)
                dp[i][j]=max(1,dp[i+1][j]-dungeon[i][j]);
            else 
          		dp[i][j]=max(1,min(dp[i+1][j]-dungeon[i][j],dp[i][j+1]-dungeon[i][j]));
        }
	return dp[0][0];
}
int main()
{
	vector< vector<int> > dungeon;
	dungeon[0][0]=-2;	
	dungeon[0][1]=-3;
	dungeon[0][2]=3;
	dungeon[1][0]=-5;
	dungeon[1][1]=-10;
	dungeon[1][2]=1;
	dungeon[2][0]=10;
	dungeon[2][1]=30;
	dungeon[2][2]=-5;
	cout<<calculateMinimumHP(dungeon);
}