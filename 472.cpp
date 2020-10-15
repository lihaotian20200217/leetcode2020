/*
    LeetCode 472
    将每个单词加入到字典树中，然后对每个单词进行dfs，若查询完该单词且count>1的时候，则加入结果数组中
*/

#include <bits/stdc++.h>
using namespace std;

class Trie
{
    public:

        Trie() {}

        void insert (string word)
        {
            Trie* node = this;
            for (auto e : word)
            {
                if (node->next[e - 'a'] == nullptr)
                {
                    node->next[e - 'a'] = new Trie();
                }
                node = node->next[e - 'a'];
            }
            node->is_string = true;
        }

    bool search (string word)
    {
        Trie* node = this;
        for (auto e : word)
        {
            if (node->next[e - 'a'] == nullptr) return false;
            node = node->next[e - 'a'];
        }
        return node->is_string;
    }

    private:
        Trie* next[26] = {nullptr};
        bool is_string = false;
};

class Solution
{
    public:
        bool dfs(Trie* ptr, int count, int start, string& e)
        {
            if (start >= e.size() && count > 1) return true;
            for (int i = start; i < e.size(); i++)
            {
                if (ptr->search(e.substr(start,i-start+1)))
                {
                    if (dfs(ptr,count+1,i+1,e)) return true;
                }
            }
            return false;
        }
        vector<string> findAllConcatenatedWordsInADict(vector<string>& words)
        {
            vector<string> res;
            Trie* root = new Trie();
            for (auto e : words)
            {
                root->insert(e);
            }
            for (auto e : words)
            {
                Trie* ptr = root;
                if (dfs(ptr,0,0,e)) res.push_back(e);
            }
            return res;
        }
};