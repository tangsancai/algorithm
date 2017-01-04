#include<iostream>
using namespace std;
class TrieNode {
public:
    TrieNode() {
    	tag=false;
     	memset(next, 0x0, sizeof(TrieNode*)*26);
    }
	TrieNode* next[26];
	bool tag;
private:
};
class Trie {
public:
	TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
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
    bool search(string word,int l,TrieNode *r) {
        if(l>=word.size())
        	return r->tag;
        for(int i=0;i<26;++i)
        	if(r->next[i]!=NULL&&((i==word[l]-'a')||(word[l]=='.')))
       		{
		       	if(search(word,l+1,r->next[i]))
        			return true;
	        }
  		return false;
    }
};

class WordDictionary {
public:
	Trie tree;
    // Adds a word into the data structure.
    void addWord(string word) {
        tree.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return tree.search(word,0,tree.root);
    }
};

int main()
{
	WordDictionary w;
	w.addWord("bad");
	w.addWord("dad");
	w.addWord("mad");
	cout<<w.search("pad")<<endl;
	cout<<w.search("bad")<<endl;
	cout<<w.search(".ad")<<endl;
	cout<<w.search("b..")<<endl;
}
