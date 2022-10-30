
#include <bits/stdc++.h>
#define MAX_CHAR 26
using namespace std;

class SuffixTrieNode
{
public:
	SuffixTrieNode *children[MAX_CHAR];
	SuffixTrieNode() // Constructor
	{

		for (int i = 0; i < MAX_CHAR; i++)
		children[i] = NULL;
	}


	void insertSuffix(string suffix);
};


class SuffixTrie
{
	SuffixTrieNode *root;
	int _countNodesInTrie(SuffixTrieNode *);
public:

	SuffixTrie(string s)
	{
		root = new SuffixTrieNode();


		for (int i = 0; i < s.length(); i++)
			root->insertSuffix(s.substr(i));
	}


	int countNodesInTrie() { return _countNodesInTrie(root); }
};


void SuffixTrieNode::insertSuffix(string s)
{
	// If string has more characters
	if (s.length() > 0)
	{

		char cIndex = s.at(0) - 'a';


		if (children[cIndex] == NULL)
			children[cIndex] = new SuffixTrieNode();


		children[cIndex]->insertSuffix(s.substr(1));
	}
}


int SuffixTrie::_countNodesInTrie(SuffixTrieNode* node)
{
	// If all characters of pattern have been processed,
	if (node == NULL)
		return 0;

	int count = 0;
	for (int i = 0; i < MAX_CHAR; i++)
	{

		if (node->children[i] != NULL)
			count += _countNodesInTrie(node->children[i]);
	}


	return (1 + count);
}


int countDistinctSubstring(string str)
{
	SuffixTrie sTrie(str);


	return sTrie.countNodesInTrie();
}

int main()
{
	string str = "ababa";
	cout << "Count of distinct substrings is "
		<< countDistinctSubstring(str);
	return 0;
}
