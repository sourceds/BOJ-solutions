#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string d;
    int32_t n, count = 0, fare = 0;
    int64_t c;
    cin >> n;
    vector<int16_t> transport;
    for (int i = 0; i < n; ++i)
    {
        cin >> d >> c;
        if (d=="jinju")
        {
            fare = c;
        }

        if (c > 1000)
        {
            count++;
        }
        else
        {
            if (fare == 0)
            {
                transport.push_back(c);
            }
            else
            {
                if (c > fare)
                {
                    count++;
                }
            }
        }
    }
    for (int i = 0; i < transport.size(); ++i)
    {
        if (transport[i] > fare)
        {
            count++;
        }
    }
    cout << fare << '\n' << count;
    return 0;
}
