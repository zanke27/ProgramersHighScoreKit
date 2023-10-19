#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string& a, string& b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> str;

    for (auto number : numbers)
        str.push_back(to_string(number));

    sort(str.begin(), str.end(), compare);

    if (str[0] == "0") return "0";

    for (auto s : str)
        answer += s;

    return answer;
}