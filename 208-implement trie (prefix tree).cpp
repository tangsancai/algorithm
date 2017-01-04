#include<iostream>
#include<vector>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
    	tag=false;
    	memset(next, 0x0, sizeof(TreeNode*)*26);
     	//for(int i=0;i<26;++i)
		 	//next.push_back(NULL);   
    }
	//vector<TrieNode*> next;//不要用vector图快，26大小的vector的实际内存是32，内存会超限的 
	TrieNode* next[26];
	bool tag;
private:
};
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    // Inserts a word into the trie.
    void insert(string word) {
    	TrieNode *r=root;
        for(int i=0;i<word.size();++i)
        {
        	if(r->next[word[i]-'a']!=NULL)
        		r=r->next[word[i]-'a'];
       		else
	   		{
  				TrieNode *tmp=new TrieNode();
  				r->next[word[i]-'a']=tmp;
  				r=tmp;
            }
        }
        r->tag=true;
    }
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *r=root;
        for(int i=0;i<word.size();++i)
        {
        	if(r->next[word[i]-'a']==NULL)
        		return false;
       		else
       			r=r->next[word[i]-'a'];
        }
        return r->tag;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *r=root;
        for(int i=0;i<prefix.size();++i)
        {
        	if(r->next[prefix[i]-'a']==NULL)
        		return false;
       		else
       			r=r->next[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

