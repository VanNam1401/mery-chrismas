#include <iostream>
#include <vector>
using namespace std;

bool arr[100];
void Eratosthenes(int n)
{
    arr[0] = arr[1] = false;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = true;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = false;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    cout << "Day so: ";
    Eratosthenes(n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == true)
        {
            cout << i << " ";
        }
    }
}