#include "general.h"

bool dfs(map<char, multiset<string> > &generator,
         const string &symbol, const string &target)
{
    if(symbol.size() > target.size())
        return false;

    if (symbol == target)
        return true;

    for(int i = 0; i < symbol.size(); ++i){
        if (symbol[i] >= 'A' && symbol[i] <= 'Z'){
            for(string pattern: generator[symbol[i]]){
                string new_pattern = symbol.substr(0, i) + pattern + symbol.substr(i + 1);
                bool r = dfs(generator, new_pattern, target);
                if (r)
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<string> generator = {"S → abc", "S → aA", "A → b", "A → c"};
    char startSymbol = 'S';
    string symbolString = "ac";

    map<char, multiset<string> > newGene;
    for(int i = 0; i < generator.size(); ++i){
        char left = generator[i][0];
        string right = generator[i].substr(6);
        newGene[left].insert(right);
    }

    if (newGene.count(startSymbol) == 0)
        return false;

    for(const string &pattern: newGene[startSymbol]){
        bool r = dfs(newGene, pattern, symbolString);
        if (r)
            return true;
    }

    return false;
}
