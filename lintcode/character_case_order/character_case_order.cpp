#include "general.h"

string solve(const string &string1)
{
    string result(string1);

    int index_character = result.size() - 1;
    for (int i = 0; i < index_character + 1; ++i)
    {
        if (result[i] >= 'A' && result[i] <= 'Z')
        {
            for ( ; index_character >= i; --index_character)
            {
                if (result[index_character] >= 'a' && result[index_character] <= 'z')
                {
                    char character = result[index_character];
                    result[index_character] = result[i];
                    result[i] = character;
                    --index_character;
                    break;
                }
            }
        }
    }

    return result;
}

int main()
{
    string string1 = "DERLKAJKFKLAJFKAKLFJKLJFa";
    cout << solve(string1);
}
