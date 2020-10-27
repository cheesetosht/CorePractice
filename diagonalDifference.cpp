#include <iostream>

using namespace std;

int main()
{
    int N, lds = 0, rds = 0;
    cin >> N;
    int arr[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (i == j)
            {
                lds += arr[i][j];
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1 - i; j >= 0;)
        {
            rds += arr[i][j];
            break;
        }
    }
    cout << abs(lds - rds) << endl;
    return 0;
}