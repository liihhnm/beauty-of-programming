#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    return (y == 0) ? x : gcd(y, x % y);
}

//避免耗时取模运算
//gcd(x, y) == gcd(x - y, y) == gcd(x - 2 * y, y), 直到一方为零。
int gcd_2(int x, int y)
{
    if (x < y)
        return gcd_2(y, x);
    if (y == 0)
        return x;
    else
        return gcd(x - y, y);
}

/*
    如果 y = k * y1，x = k * x1。那么有 f(x，y） = k * f(x1，y1)。
    另外，如果 x = p * x1, 假设 p 是素数，并且  y % p != 0，那么 f(x, y) = f(p * x1, y) = f(x1, y)。
    取 p = 2
    1）若 x, y 为偶数，f(x, y) = 2 * f(x / 2, y / 2) = 2 * f(x >> 1, y >> 1)
    2）若一方为奇数，一方为偶数（设 x 为偶数），f(x, y) = f(x / 2, y) = f(x >> 1, y)
    3）若均为奇数， f(x, y) = f(y, x - y)。那么 (x - y) 是一个偶数，下一步一定会有除以 2 的操作。
    time O(log(max(x, y)))

    利用移位运算和减法运算，避开了大整数 除法，提高了算法的效率。
*/
int gcd_3(int x, int y)
{
    if (x < y)
        return gcd_3(y, x);
    if (y == 0)
        return x;

    if (x % 2 == 0)
    {
        if (y % 2 == 0)
            return 2 * gcd_3(x / 2, y / 2);
        else
            return gcd_3(x / 2, y);
    }
    else
    {
        if (y % 2 == 0)
            return gcd_3(x, y / 2);
        else
            return gcd_3(y, x - y);
    }
}