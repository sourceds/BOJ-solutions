#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> seq[i];
    }
    int maxlen_asc = 0;
    int maxlen_dsc = 0;
    int len;

    len = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (seq[i] <= seq[i+1])
        {
            len++;
        }
        else
        {
            if (len > 1)
            {
                i--;
            }
            if (maxlen_asc < len)
            {
                maxlen_asc = len;
            }
            len = 1;
        }
    }
    if (maxlen_asc < len)
    {
        maxlen_asc = len;
    }

    len = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (seq[i] >= seq[i+1])
        {
            len++;
        }
        else
        {
            if (len > 1)
            {
                i--;
            }
            if (maxlen_dsc < len)
            {
                maxlen_dsc = len;
            }
            len = 1;
        }
    }
    if (maxlen_dsc < len)
    {
        maxlen_dsc = len;
    }
                
    cout << max(maxlen_asc, maxlen_dsc);
    return 0;
}
