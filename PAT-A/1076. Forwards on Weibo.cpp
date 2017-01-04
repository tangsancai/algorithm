#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
 
using namespace std;
 
const int N = 1005;
 
struct E
{
    int node;
};
vector<E> v[N];
 
int mark[N];
 
void add_edge(int a, int b)
{
    E tmp;
    tmp.node = b;
 
    v[a].push_back(tmp);
}
 
struct ANS
{
    int num;
    int lev;
};
 
void BFS(int x, int ll)
{
    queue<ANS> q;
    ANS tmp;
    tmp.lev = 0;
    tmp.num = x;
    q.push(tmp);
    mark[x] = 1;
 
    int level = 0;
    int ans = 0;
    while (!q.empty())
    {
        ANS top = q.front();
 
        int node = top.num;
        int lev = top.lev;
        if (lev >= ll) break;
        q.pop();
 
        for (int i = 0; i < v[node].size(); i++)
        {
            if (mark[v[node][i].node] == 0)
            {
                mark[v[node][i].node] = 1;
 
                tmp.lev = lev + 1;
                tmp.num = v[node][i].node;
 
                //printf("%d %d\n", tmp.num, tmp.lev);
                ans++;
                q.push(tmp);
            }
        }
    }
 
    printf("%d\n", ans);
}
         
 
int main()
{
    int n, ll;
 
    while (scanf("%d%d", &n, &ll) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            int k, a;
            scanf("%d", &k);
            while (k--)
            {
                scanf("%d", &a);
                add_edge(a, i);
            }
        }
        int query_num, query;
        scanf("%d", &query_num);
        while (query_num--)
        {
            scanf("%d", &query);
            memset(mark, 0, sizeof(mark));
            BFS(query, ll);
        }
    }
    return 0;
}