#include "general.h"

int main()
{
    string s = "(1+(4+5+2)-3)+(6+8)";

    stack<int> stack;
    int result = 0;
    int number = 0;
    int sign = 1;

    for(char c: s){
        if(isdigit(c))
            number = 10 * number + (int)(c - '0');
        else if(c == '+'){
            result += sign * number;
            number = 0;
            sign = 1;
        }
        else if(c == '-'){
            result += sign * number;
            number = 0;
            sign = -1;
        }
        else if(c == '('){
            stack.push(result);
            stack.push(sign);
            sign = 1;
            result = 0;
        }
        else if(c == ')'){
            result += sign * number;
            number = 0;
            result *= stack.top();
            stack.pop();
            result += stack.top();
            stack.pop();
        }
    }

    if(number != 0)
        result += sign * number;

    return result;
}