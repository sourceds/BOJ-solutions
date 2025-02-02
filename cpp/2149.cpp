#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string key, encrypt;
    cin >> key >> encrypt;
    int horizontal_len = key.length();
    int vertical_len = encrypt.length() / key.length();

    vector<pair<char, int>> sorted_key;
    vector<vector<char>> before_arr(vertical_len, vector<char>(horizontal_len));
    vector<vector<char>> after_arr(vertical_len, vector<char>(horizontal_len));

    for (int i = 0; i < key.length(); ++i)
    {
        sorted_key.push_back(make_pair(key[i], i));
    }
    stable_sort(sorted_key.begin(), sorted_key.end(), [](auto a, auto b) { return a.first < b.first; });

    int idx = 0;
    for (int j = 0; j < horizontal_len; ++j)
    {
        for (int i = 0; i < vertical_len; ++i)
        {
            before_arr[i][j] = encrypt[idx];
            idx++;
        }
    }

    for (int j = 0; j < horizontal_len; ++j)
    {
        for (int i = 0; i < vertical_len; ++i)
        {
            after_arr[i][sorted_key[j].second] = before_arr[i][j];
        }
    }

    for (int i = 0; i < vertical_len; ++i)
    {
        for (int j = 0; j < horizontal_len; ++j)
        {
            cout << after_arr[i][j];
        }
    }
    return 0;
}
