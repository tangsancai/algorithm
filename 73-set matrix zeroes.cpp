#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void setZeroes(vector< vector<int> >& matrix) 
{
	if(matrix.empty()) 
		return ;
 	int rowSize=matrix.size(),colSize=matrix[0].size();
  	bool firstRow=false,firstCol=false;
    for(int c=0;c<colSize;++c)
		if(matrix[0][c]==0)
			firstRow=true;
   	for(int r=0;r<rowSize;++r)
	   	if(matrix[r][0]==0)
		   	firstCol=true;
    for(int r=1;r<rowSize;++r)
    	for(int c=1;c<colSize;++c)
     		if(matrix[r][c]==0)
		 		matrix[0][c]=matrix[r][0]=0;
    for(int c=1;c<colSize;++c) 
    	if(matrix[0][c]==0)
     		for(int r=1;r<rowSize;++r)
       			matrix[r][c]=0;
    for(int r = 1; r < rowSize; ++r) 
    	if(matrix[r][0]==0)
     		for(int c=1;c<colSize;++c)
       			matrix[r][c]=0;
    if(firstRow)
		for(int c=0;c<colSize;++c)
			matrix[0][c]=0;
    if(firstCol) 
		for(int r=0;r<rowSize;++r) 
			matrix[r][0]=0;
}