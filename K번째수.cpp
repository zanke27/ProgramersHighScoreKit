#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> array = { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };
	vector<int> answer;

    for (int i = 0; i < commands[0].size(); i++)
    {
        vector<int> slice(
            array.begin() + commands[i][0]-1,
            array.begin() + commands[i][1]);

        sort(slice.begin(), slice.end(), less<int>());

        answer.push_back(slice[commands[i][2]-1]);
    }

    for (auto i : answer)
        cout << i;

}
