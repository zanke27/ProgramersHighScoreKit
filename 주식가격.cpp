#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
    vector<int> prices = { 1,2,3,2,3 };
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for (int i = 0; i < size; i++) {
        while (!s.empty() && prices[s.top()] > prices[i]) {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < size; i++)
        cout << answer[i] << " ";

    cout << endl;

    while (!s.empty()) {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }

    for (int i = 0; i < size; i++)
        cout << answer[i] << " ";
}