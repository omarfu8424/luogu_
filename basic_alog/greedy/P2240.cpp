#include <iostream>
#include <algorithm>

using namespace std;

struct gold
{
    double m = 0;
    double v = 0;
};

bool comp(gold a, gold b)
{
    if (a.v * b.m - b.v * a.m > 0)
        return true;
    else
        return false;
}

int main()
{
    int N, T;
    cin >> N >> T;
    gold g[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> g[i].m >> g[i].v;
    }
    sort(g, g + N, comp);

    double res = 0;
    for (int i = 0; i < N && T >= 0; ++i)
    {
        if (T >= g[i].m)
        {
            res += g[i].v;
            T -= g[i].m;
            continue;
        }
        else
        {
            double per = g[i].v / g[i].m;
            res += per * T;
            T = 0;
        }
    }

    printf("%.2lf", res);
    return 0;
}