#include <iostream>
using namespace std;

bool arr[100001];
void Eratosthenes(int n)
{
    arr[0] = arr[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = 1;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = 0;
            }
        }
    }
}
int greatestCommonPrimeDivisor(int a, int b)
{
    int min = a > b ? b : a;
    Eratosthenes(min);
    for (int i = min; i > 0; i--)
    {
        if (arr[i] != 0 && a % i == 0 && b % i == 0)
            return i;
    }
    return -1;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cin.ignore();
    cout << greatestCommonPrimeDivisor(a, b);
}
