#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BIGINT
{
    vector<int> numbers;

    static void normalize(vector<int> &v)
    {
        while (v.size() > 1 && v.back() == 0)
            v.pop_back();
    }

public:
    BIGINT() { numbers.push_back(0); }

    BIGINT(int value) { *this = value; }

    BIGINT &operator=(int r)
    {
        numbers.clear();
        if (r == 0)
            numbers.push_back(0);
        else
        {
            while (r > 0)
            {
                numbers.push_back(r % 10);
                r /= 10;
            }
        }
        return *this;
    }

    BIGINT &operator+=(const BIGINT &rhs)
    {
        int carry = 0;
        size_t maxLen = max(numbers.size(), rhs.numbers.size());
        vector<int> result(maxLen + 1, 0);

        for (size_t i = 0; i < maxLen || carry; ++i)
        {
            int a = i < numbers.size() ? numbers[i] : 0;
            int b = i < rhs.numbers.size() ? rhs.numbers[i] : 0;
            int sum = a + b + carry;
            result[i] = sum % 10;
            carry = sum / 10;
        }

        numbers = std::move(result);
        normalize(numbers);
        return *this;
    }

    BIGINT operator+(const BIGINT &rhs) const
    {
        BIGINT temp = *this;
        temp += rhs;
        return temp;
    }

    friend ostream &operator<<(ostream &os, const BIGINT &bigint)
    {
        for (int i = bigint.numbers.size() - 1; i >= 0; --i)
            os << bigint.numbers[i];
        return os;
    }
};

int main()
{
    int m, n;
    cin >> m >> n;

    vector<BIGINT> dp(n + 1); // dp[i]表示从m到i的路线数

    dp[m] = 1;
    if (m + 1 <= n)
        dp[m + 1] = 1;

    for (int i = m + 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;
    return 0;
}