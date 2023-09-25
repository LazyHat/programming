#include <string>
#include <iostream>

using namespace std;

void add_zeros_front(string &a, uint64_t count_zeros)
{
    for (uint64_t i = 0; i < count_zeros; i++)
    {
        a = '0' + a;
    }
}

/// @brief sum strings
/// @param a first operand
/// @param b second operand
/// @param res = a+b
void sum_strings(string &a, string &b, string &res)
{
    res = "";
    bool nextdigit = false;
    if (a.size() > b.size())
        add_zeros_front(b, a.size() - b.size());
    else
        add_zeros_front(a, b.size() - a.size());
    add_zeros_front(res, a.size());
    for (uint64_t i = a.size(); i > 0; i--)
    {
        char r = res[i - 1] + a[i - 1] + b[i - 1] - ('0' * 2);
        if (r > '9')
        {
            r = r - 10;
            if (i == 1)
                nextdigit = true;
            else
                res[i - 2]++;
        }
        res[i - 1] = r;
    }
    if (nextdigit)
        res = '1' + res;
}

/// @brief subtact strings
/// @param a first operand
/// @param b second operand
/// @param res = a-b
void subtact_strings(string &a, string &b, string &res)
{
    res = "";
    bool nextdigit = false;
    if (a.size() > b.size())
        add_zeros_front(b, a.size() - b.size());
    else
        add_zeros_front(a, b.size() - a.size());
    add_zeros_front(res, a.size());
    for (uint64_t i = a.size(); i > 0; i--)
    {
        char r = res[i - 1] + a[i - 1] - b[i - 1];
        if (r < '0')
        {
            r = r + 10;
            if (i == 1)
                nextdigit = true;
            else
                res[i - 2]--;
        }
        res[i - 1] = r;
    }
    while (true)
    {
        if (res[0] == '0')
            res = res.substr(1);
        else
            break;
    }
    if (nextdigit)
    {
        subtact_strings(b, a, res);
        res = '-' + res;
    }
}

void add_strings(string &a, string &b, string &res)
{
    bool am = false, bm = false;
    if (a[0] == '-')
    {
        a = a.substr(1);
        am = true;
    }
    if (b[0] == '-')
    {
        b = b.substr(1);
        bm = true;
    }
    if (am && bm)
    {
        sum_strings(a, b, res);
        res = '-' + res;
    }
    else if (am)
        subtact_strings(b, a, res);
    else if (bm)
        subtact_strings(a, b, res);
    else
        sum_strings(a, b, res);
}

void mul_strings(string &a, string &b, string &res)
{
    res = "";
    bool nextdigit = false;
    if (a.size() > b.size())
        add_zeros_front(b, a.size() - b.size());
    else
        add_zeros_front(a, b.size() - a.size());
    add_zeros_front(res, a.size());
    for (uint64_t i = a.size(); i > 0; i--)
    {
        for (uint8_t j = 0; j < a[i - 1] - '0'; j++)
        {
            add_strings(r, b, res);
        }
    }
}

int main()
{
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    mul_strings(a, b, c);
    cout << c;
}