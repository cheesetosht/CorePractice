#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, n, z, N;
    p = 0;
    n = 0;
    z = 0;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] > 0)
        {
            p++;
        }
        else if (arr[i] < 0)
        {
            n++;
        }
        else
        {
            z++;
        }
    }
    cout << setprecision(6) << (float)p / N << endl;
    cout << setprecision(6) << (float)n / N << endl;
    cout << setprecision(6) << (float)z / N << endl;
}