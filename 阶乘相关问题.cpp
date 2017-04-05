#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <bitset>

using namespace std;

/*
    问题1：N!末尾有多少个0？
    分析：如果N! = K * 10 ^ M，且 K 不能被 10 整除，那么 N! 末尾有 M 个0。
          考虑对 N！ 进行质因数分解，N! = 2 ^ x + 3 ^ y + 5 ^ z + ...，
          由于 10 = 2 * 5，M 只与 x、z 相关。
          所以 M = min(x, z)，且 x >= z。故只需要计算 z 的值即可。
    解法一：计算 i (i = 1, 2, ..., N) 的因式分解中 5 的指数， 然后求和。
    解法二：Z = [N / 5] + [N / 5 ^ 2] + ...
            公式中，不大于 N 的数中 5 的倍数贡献一个 5， 5 ^ 2 的倍数再贡献一个5...
*/

int zero_num_1(unsigned n)
{
    int num = 0;
    for (int i = 1; i <= n; ++i)
    {
        int temp = i;
        while (temp % 5 == 0)
        {
            num++;
            temp /= 5;
        }
    }
    return num;
}

int zero_num_2(unsigned n)
{
    int num = 0;
    while (n)
    {
        num += n / 5;
        n /= 5;
    }
    return num;
}

long long unsigned factorial(unsigned n)
{
    if (n == 0)
        return 1;
    long long unsigned result = 1;
    for (unsigned i = 1; i <= n; ++i)
        result *= i;
    return result;
}

/*
    问题2：N! 的二进制表示中最低位 1 的位置。 eg： N = 3, N! = 6 => 1010，最低位在第二位。
    分析：等同于求 N! 含有质因数 2 的个数。
    解法一：和上题公式类似 [N / 2] + [N / 2 ^ 2] + ...
    解法二：N! 含有质因数 2 的个数， 还等于 N 减去 N 的 二进制表示中 1 的数目。
*/

int lowest_one_1(unsigned n)
{
    int num = 0;
    while (n)
    {
        num += (n >> 1);
        n >>= 1;
    }
    return num;
}

int lowest_one_2(unsigned n)
{
    int bit_count = 0, temp = n;
    while (temp)
    {
        bit_count++;
        temp &= (temp - 1);
    }
    return n - bit_count;
}

int main()
{
    //cout << ULLONG_MAX << endl;
    unsigned t1 = 15, t2 = 20;
    long long unsigned f1 = factorial(t1), f2 = factorial(t2);
    cout << f1 << endl << zero_num_1(t1) << " " << zero_num_2(t1) << endl
        << f2 << endl << zero_num_1(t2) << " " << zero_num_2(t2) << endl;

    cout << bitset<sizeof(long long unsigned) * 8>(f1) << endl
        << lowest_one_1(t1) << " " << lowest_one_2(t1) << endl
        << bitset<sizeof(long long unsigned) * 8>(f2) << endl
        << lowest_one_1(t2) << " " << lowest_one_2(t2) << endl;
}