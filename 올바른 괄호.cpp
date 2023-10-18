#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    string s = "()()";

    bool answer = true;

    int result = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (result < 0) break;

        if (s[i] == '(') result++;
        else if (s[i] == ')') result--;
    }

    if (result == 0) answer = true;
    else answer = false;

    cout << answer;
}