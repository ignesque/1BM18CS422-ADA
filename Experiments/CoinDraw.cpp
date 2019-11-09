#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int m, int V)
{
    int table[V + 1];

    table[0] = 0;

    for (int i = 1; i <= V; i++)
        table[i] = INT_MAX;

    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < m; j++)
            if (coins[j] <= i)
            {
                int sub_res = table[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i]){
                    table[i] = sub_res + 1;
                }
            }
    }
    return table[V];
}

int main()
{
    int size, v;
    cout << "Enter number of coins:";
    cin >> size;
    int coins[size];
    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value of coin " << i + 1 << ":";
        cin >> coins[i];
    }
    cout << "\nEnter the final value:";
    cin >> v;
    cout << "\nMinimum coins required is " << minCoins(coins, size, v);
    return 0;
}
