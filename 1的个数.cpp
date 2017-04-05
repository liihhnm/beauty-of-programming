#include <iostream>

using namespace std;

typedef unsigned long long ULL;

/*
    给定一十进制正整数， 写下从 1 开始，到 N 的所有整数，然后数出其中所有 “1” 的个数。
    解法一：从 1 遍历到 N ，数出其中每个数的 “1”。
            time O(N * logN)
    解法二：按个、十、百...位来数。
            对某一位的数有三种情况，（以103、113、123的百位来举例）
            1）如果小于1，即这里为0。百位上的 1 次数由更高的那些位决定。
                num = higher_num * factor (num = 1 * 10)
            2）如果等于1。由更高位和低位决定。
                num = higher_num * factor + lower_num + 1 (num = 1 * 10 + 3 + 1)
            3）如果大于1。由高位决定。
                num = (high_num + 1) * factor (num = (1 + 1) * 10)
            time O(logn)
*/
ULL count_one_1(ULL n)
{
    ULL num = 0;
    for (ULL i = 1; i <= n; ++i)
    {
        ULL temp = i;
        while (temp != 0)
        {
            num += (temp % 10 == 1) ? 1 : 0;
            temp /= 10;
        }
    }
    return num;
}

ULL count_one_2(ULL n)
{
    ULL num = 0;
    ULL factor = 1;
    ULL higher_num = 0, current_num = 0, lower_num = 0;

    while (n / factor != 0)
    {
        higher_num = n / (factor * 10);
        current_num = (n / factor) % 10;
        lower_num = n - (n / factor) * factor;

        if (current_num < 1)
            num += higher_num * factor;
        else if (current_num == 1)
            num += higher_num * factor + lower_num + 1;
        else
            num += (higher_num + 1) * factor;

        factor *= 10;
    }
    return num;
}

ULL count_taget(ULL n, int target)
{
    ULL num = 0;
    ULL factor = 1;
    ULL higher_num = 0, current_num = 0, lower_num = 0;
    
    while (n / factor != 0)
    {
        higher_num = n / (factor * 10);
        current_num = n / factor % 10;
        lower_num = n - (n / factor) * factor;
        
        if (current_num < target)
            num += higher_num * factor;
        else if (current_num == target)
        {
            if (target == 0)
                num += (higher_num - 1) * factor + lower_num + 1;
            else
                num += higher_num * factor + lower_num + 1;
        }
        else
        {
            if (target == 0)
                num += higher_num * factor;
            else
                num += (higher_num + 1) * factor;
        }
        
        factor *= 10;
    }
    return num;
}

int main()
{
    ULL t1 = 123, t2 = 999;
    cout << t1 << endl << count_one_1(t1) << " " << count_one_2(t1) << endl
           << t2 << endl << count_one_1(t2) << " " << count_one_2(t2) << endl;
}