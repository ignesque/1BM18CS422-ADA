#include <stdio.h>
#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    int res = K[n][W];
    cout << "\nOptimal value is " << res;
    w = W;
    cout << "\nItems considered are ";
    for (i = n; i > 0 && res > 0; i--)
    {
        if (res == K[i - 1][w])
            continue;
        else
        {
            cout << "\nItem " << i << " with weight " << wt[i - 1] << " and value " << val[i - 1];
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }
}

int main()
{
    int i, j, W, ks, opt;
    cout << "Enter size of KnapSack:";
    cin >> W;
    cout << "How many items? ";
    cin >> ks;
    int val[ks], wt[ks];
    for (i = 0; i < ks; i++)
    {
        cout << "Enter Weight of item " << i + 1 << ":";
        cin >> wt[i];
        cout << "Enter Value of item " << i + 1 << ":";
        cin >> val[i];
    }
    int n = sizeof(val) / sizeof(val[0]);
    knapSack(W, wt, val, n);
    return 0;
}
