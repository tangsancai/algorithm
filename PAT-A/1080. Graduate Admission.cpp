#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=40005;
const int maxm=101;
int n,m,k;
int num[maxm];
int lastRank[maxm];
vector<int> mm[maxm];
struct stu
{
    int id;
    int GE,GI,fin;
    int pre[6];
    int rank;
};
stu tt[maxn];
bool cmp(stu a,stu b)
{
    if(a.fin!=b.fin)
        return a.fin>b.fin;
    else
        return a.GE>b.GE;
}
void Init()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<m; i++)
		scanf("%d",&num[i]);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&tt[i].GE,&tt[i].GI);
        tt[i].fin=(tt[i].GE+tt[i].GI);
        tt[i].id=i;
        for(int j=0; j<k; j++)
        {
            scanf("%d",&tt[i].pre[j]);
        }
    }
    sort(tt,tt+n,cmp);
    for(int i=0; i<maxm; i++) mm[i].clear();
    tt[0].rank=0;
    for(int i=1; i<n; i++)
    {
        if(tt[i].fin==tt[i-1].fin && tt[i].GE==tt[i-1].GE) 
			tt[i].rank=tt[i-1].rank;
        else
            tt[i].rank=i;
    }
}
void Select()
{
    for(int i=0; i<n; i++)
    {
        int curstuid=tt[i].id;
        for(int j=0; j<k; j++)
        {
            int schoolid=tt[i].pre[j];
            if(mm[schoolid].size()<num[schoolid])
            {
                mm[schoolid].push_back(curstuid);
                lastRank[schoolid]=tt[i].rank;   //当前学生的排名 非tt[curstuid].rank
                break;
            }
            else if(mm[schoolid].size()>0)
            {
                if(tt[i].rank==lastRank[schoolid])
                {
                    mm[schoolid].push_back(curstuid);
                    break;
                }
            }
        }
    }
}
void output()
{
    for(int i=0; i<m; i++)
    {
        if(mm[i].size()==0)
            printf("\n");
        else
        {
            sort(mm[i].begin(),mm[i].end());
            for(int j=0; j<mm[i].size(); j++)
            {
                if(j==0)
					printf("%d",mm[i][j]);
                else 
					printf(" %d",mm[i][j]);
            }
            printf("\n");
        }
    }
}
int main()
{
    Init();
    Select();
    output();
    return 0;
}
