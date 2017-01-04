/*
1.设置录入的vector足够大，直接把vector的index与节点的address匹配，这在节点数很少的情况下可用；
2.从给定头结点指针开始，顺序找到整个链，存储在vsorted，要注意有些节点可能是废节点，所以排序后找出来的链长度可能小于初始录入的节点数目
3.将排序后的节点每K个为单位录入到要输出的最后结果的vector中（表示为vout），注意剩余不足K个节点顺序添加到后边；
4.修改除最后一个节点之外的所有节点的next指针，并输出每个节点信息；
5.输出最后一个节点信息，注意next为-1
*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct node{
	int address;
	int val;
	int next;
}tmp;
int main(){
	vector<node>vin(100006);
	vector<node>vsort;
	vector<node>vout;
	int first,n,k,i,j;
	while(scanf("%d%d%d",&first,&n,&k)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d%d%d",&tmp.address,&tmp.val,&tmp.next);
			vin[tmp.address]=tmp;
		}
		if(first==-1){
			printf("-1\n");
			continue;
		}
		while(first!=-1){
			vsort.push_back(vin[first]);
			first=vin[first].next;
			}
		int len=vsort.size();

		/*for(int ii=0;ii<len;ii++){
			printf("***   %05d %d %05d\n",vsort[ii].address,vsort[ii].val,vsort[ii].next);
		}*/

		
		for(i=k;i<=len;i+=k){
			for(j=i-1;j>=i-k;j--){
				vout.push_back(vsort[j]);
			}
		}
		for(j=(len/k)*k;j<len;j++){
			vout.push_back(vsort[j]);
		}


		/*for(int ii=0;ii<len;ii++){
			printf("^^^   %05d %d %05d\n",vout[ii].address,vout[ii].val,vout[ii].next);
		}*/

		for(i=0;i<len-1;i++){
			vout[i].next=vout[i+1].address;
			printf("%05d %d %05d\n",vout[i].address,vout[i].val,vout[i].next);
		}
		if(len>=1)printf("%05d %d -1\n",vout[len-1].address,vout[len-1].val);

		}
	return 0;
}
/*
00100 6 1
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
*/