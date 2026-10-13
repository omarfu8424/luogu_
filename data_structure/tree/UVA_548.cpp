#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000
int lc[MAXN], rc[MAXN];
vector<int> in, post;

int buildTree(int l_in, int r_in, int l_post, int r_post)
{ // return root
    if (l_in > r_in)
    {
        return 0;
    }
    int root = post[r_post];
    int p;
    for (p = l_in; (p < in.size()) && (in[p] != root); ++p)
        ;
    int count = p - l_in; // size of left subtree
    lc[root] = buildTree(l_in, p - 1, l_post, l_post + count - 1);
    rc[root] = buildTree(p + 1, r_in, l_post + count, r_post-1);
    return root;
}

int best, best_sum;
void dfs(int w, int sum)
{
    sum += w;
    if (!lc[w] && !rc[w] && (sum < best_sum || (sum == best_sum && w < best)))
    { // leaf
        best = w;
        best_sum = sum;
    }
    // else deep down
    if (lc[w])
        dfs(lc[w], sum);
    if (rc[w])
        dfs(rc[w], sum);
}

int main()
{
    string line1, line2;
    if (getline(cin, line1) && getline(cin, line2))
    {
        in.clear();
        post.clear();

        stringstream ss1(line1), ss2(line2);
        int x;
        while (ss1 >> x)
            in.push_back(x);
        while (ss2 >> x)
            post.push_back(x);

        memset(lc, 0, sizeof(lc));
        memset(rc, 0, sizeof(rc));

        buildTree(0, in.size() - 1, 0, post.size() - 1);
        best_sum = INT_MAX;
        dfs(post.back(), 0);
        cout << best << '\n';
    }
    return 0;
}