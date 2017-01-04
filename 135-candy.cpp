#include<iostream>
#include<vector>
using namespace std;

int candy(vector<int>& ratings) 
{
	const int n = ratings.size();
    if (n <= 1) return n;      
    int C[n];
    C[0] = 1;
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i-1]) C[i] = C[i-1] + 1;
        else C[i] = 1;
    }
    int result = C[n-1];
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1]) {
        	C[i] = max(C[i], C[i+1] + 1);
         }
         result += C[i];
    }
    return result;
}
int main()
{
	vector<int> v;/*
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(2);
	v.push_back(2);
	v.push_back(1);
	v.push_back(0);
	v.push_back(-1);
	v.push_back(6);
	v.push_back(9);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
	v.push_back(4);*/
	v.push_back(22);
	v.push_back(2);
	v.push_back(2);
	cout<<candy(v)<<endl;
}