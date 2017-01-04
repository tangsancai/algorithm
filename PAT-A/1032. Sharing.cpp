#include<iostream>
#include<map>
#include<vector>
#include<set>

typedef struct Node
{
  int adress;
  Node* next;
  Node(int _a = 0, Node* _next = NULL):adress(_a),next(_next){};
}Node, *PNode;

void ReleaseList(Node* list)
{
  while(list)
  {
    Node* pNext = list->next;
    delete list;
    list = pNext;
  }
}

int FindCommonIndex(Node* list1, Node* list2)
{
  int res = -1;
  std::set<int> set;
  while(list1)
  {
    set.insert(list1->adress);
    list1 = list1->next;
  }
  std::set<int>::iterator it;
  while(list2)
  {
    it=set.find(list2->adress);
    if(it != set.end())
    {
      res = list2->adress;
      break;
    }
    list2 = list2->next;
  }
  return res;
}
void BuildList(Node* &list, std::map<int, int>& map)
{
  std::map<int, int>::iterator it;
  int key = list->adress;
  it=map.find(key);
  Node** p = &list->next;
  while(it != map.end())
  {
    (*p) = new Node;
    (*p)->adress = (*it).second;
    key = (*p)->adress;
    it=map.find(key);
    p = &(*p)->next;
  }
}
int main()
{
  int s1, s2, n;
  while( scanf("%d%d%d", &s1, &s2, &n) != EOF )
  {
    int a, b;
    char c;
    std::map<int, int> map;
    for(int i = 0; i < n; ++i)
    {
      scanf("%d%*c%c%d", &a, &c, &b);
      map[a] = b;
    }
    Node* list1 = new Node;
    list1->adress = s1;
    Node* list2 = new Node;
    list2->adress = s2;
    //build list
    BuildList(list1, map);
    BuildList(list2, map);
    //find common index
    int comIdx = FindCommonIndex(list1, list2);
    //release
    ReleaseList(list1);
    ReleaseList(list2);

    if(comIdx == -1)
      printf("-1\n");
    else 
      printf("%05d\n", comIdx);
  }
  return 0;
}