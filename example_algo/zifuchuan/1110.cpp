#include "general.h"

/*
 * 思路是使用字典树, 原因是一个单词只能匹配一个, 且匹配最短的那个
 */
class TrieNode
{
public:
    TrieNode* child[26];
    bool is_end;
    TrieNode()
    {
        is_end = false;
        for(int i = 0; i < 26; ++i)
            child[i] = nullptr;
    }
};

TrieNode* root = new TrieNode();

void insert(string &str)
{
    TrieNode *p = root;
    for(int i = 0; i < str.size(); ++i){
        int pos = str[i] - 'a';
        if(p->child[pos] == nullptr)
            p->child[pos] = new TrieNode();
        p = p->child[pos];
    }

    p->is_end = true;
}

string getPrefix(string &str)
{
    TrieNode *p = root;
    for(int i = 0; i < str.size(); ++i){
        int pos = str[i] - 'a';

        if(p->child[pos] == nullptr)
            return str;
        if(p->child[pos]->is_end)
            return str.substr(0, i + 1);
        p = p->child[pos];
    }

    return str;
}

int main()
{
    vector<string> dict = {"go", "begin", "make","end"};
    string sentence = "a good beginning makes a good ending";

    for(int i = 0; i < dict.size(); ++i)
        insert(dict[i]);

    vector<string> words;
    string word = "";
    sentence += " ";
    string result = "";

    for(int i = 0; i < sentence.size(); ++i){
        if(sentence[i] != ' ')
            word += sentence[i];
        else{
            words.push_back(word);
            word = "";
        }
    }

    for(int i = 0; i < words.size(); ++i){
        result += getPrefix(words[i]);
        if(i < words.size() - 1)
            result += " ";
    }

    cout << result;
}