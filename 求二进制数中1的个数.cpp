#include <iostream>
//http://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html

using namespace std;

int bit_count_1(unsigned n)
{
    int num = 0;
    while (n)
    {
        if (n % 2 == 1)
            num++;
        n /= 2;
    }
    return num;
}

int bit_count_2(unsigned n)
{
    int num = 0;
    while (n)
    {
        num += (n & 0x01);
        n /= 2;
    }
    return num;
}

//////////////////////////////
int bit_count_3(unsigned n)
{
    int num = 0;
    while (n)
    {
        n &= (n - 1);
        num++;
    }
    return num;
}
//////////////////////////////

int bit_count_4(unsigned n)
{
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

    return n;
}

int bit_count_5(unsigned n)
{
    unsigned temp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
    return ((temp + (temp >> 3)) & 030707070707) % 63;
}

struct _byte
{
    unsigned a : 1;
    unsigned b : 1;
    unsigned c : 1;
    unsigned d : 1;
    unsigned e : 1;
    unsigned f : 1;
    unsigned g : 1;
    unsigned h : 1;
};

int bit_count_6(unsigned char b)
{
    struct _byte *by = (struct _byte*)&b;
    return (by->a + by->b + by->c + by->d + by->e + by->f + by->g + by->h);
}

int main()
{
    unsigned i = 255;
    cout << bit_count_1(i) << endl
        << bit_count_2(i) << endl
        << bit_count_3(i) << endl
        << bit_count_4(i) << endl
        << bit_count_5(i) << endl
        << bit_count_6(i) << endl;
}