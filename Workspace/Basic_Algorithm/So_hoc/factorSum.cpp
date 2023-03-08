#include <iostream>
using namespace std;

// Hàm solve là hàm trả con số sum của từng giá trị n , chạy đến khi mà tìm ra tổng là số nguyên tố
//   => Từ hàm solve sẽ tách nhỏ ra và nó tìm từng ước số cộng lại với nhau ra một kết quả và trả về hàm factorSum()
//      => Khi nhận thấy hàm solve() đã không còn ước số thì nó trả lại con số chính nó, khi đó hàm n ở factorSum sẽ so sánh với sum ở solve bằng nhau thì dừng và in ra kq.
int solve(int n)
{
    int k = 2;
    int sum = 0;
    while (n >= 2)
    {
        while (n % k == 0)
        {
            sum += k;
            n /= k;
        }
        k++;
    }
    return sum;
}
// hàm factorSum() mình có 1 vòng while
//     Nhiệm vụ của nó sẽ dừng khi đúng kết quả không có thừa số
int factorSum(int n)
{
    while (n != solve(n))
    {
        n = solve(n);
    }
    return n;
}
int main()
{
    int n;
    cin >> n;
    cout << factorSum(n);
}