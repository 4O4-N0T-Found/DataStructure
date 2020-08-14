// 计算 x 的 n 次幂，leetcode 50题。
#include <iostream>
using namespace std;

double quikMul(double x, long long n) {
    if(n == 0)  return 1.0;
    else {
        double y = quikMul(x, n/2);
        return n%2==0 ? y*y : y*y*x;
    }
}

double myPow(double x, int n) {
    long long N = n;
    return n > 0 ? quikMul(x, N) : (1.0 / quikMul(x, -N));
}

int main() {
    cout << myPow(2, -2);
}