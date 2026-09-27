#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<int> primeSet = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97};

int main()
{
    string s;
    cin >> s;
    long long cnt = 0;
    for (int i = 0; i < s.size() - 1; ++i)
    {
        int num = 0;
        num += (s[i] - '0') * 10 + s[i + 1] - '0';
        if (primeSet.count(num))
            cnt += num;
    }
    cout << cnt;
    return 0;
}
