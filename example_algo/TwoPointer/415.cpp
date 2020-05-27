#include "general.h"

int main()
{
    string s = "A man, a plan, a canal: Panama";

    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        while (!isdigit(s[i]) && !isalpha(s[i]) && i < j)
            i++;
        while (!isdigit(s[j]) && !isalpha(s[j]) && i < j)
            j--;
        if (i < j && tolower(s[i]) != tolower(s[j]))
            return false;
    }
    return true;

}