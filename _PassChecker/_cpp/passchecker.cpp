#include <string>

int strongPasswordChecker(std::string password)
{
    int add = 0;
    int del = 0;
    int replace = 0;
    int row = 0;
    if (password.size() < 6)
        add += 6 - password.size();
    if (password.size() > 20)
        del += password.size() - 20;
    char c = 0;
    int cup, clo, cnum;
    cup = clo = cnum = 0;
    int count = 1;
    for (int i = 0; i < password.size(); i++)
    {
        if (password[i] == c)
        {
            count++;
            if (count >= 3)
            {
                row++;
                count = 0;
            }
        }
        else
        {
            c = password[i];
            count = 1;
        }
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            cup++;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            clo++;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            cnum++;
        }
    }
    if (cnum == 0)
        replace++;
    if (clo == 0)
        replace++;
    if (cup == 0)
        replace++;
    row -= del;
    if (row < 0)
        row = 0;
    while (replace < row)
        replace++;
    replace -= add;
    if (replace < 0)
        replace = 0;
    return replace + add + del;
}

int main()
{
    int pass = strongPasswordChecker("bbaaaaaaaaaaaaaaacccccc");
    int pas2 = strongPasswordChecker("bbaaCaaBaaCaa1aaccBcc");
    pass = pass;
    pas2 = pas2;
}