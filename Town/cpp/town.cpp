#include <iostream>
class Arge
{
public:
    static int nbYear(int p0, double percent, int aug, int p)
    {
        int age = 0;
        do
        {
            p0 += (p0 * percent / 100) + aug;
            age++;
        } while (p0 < p);
        return age;
    }
};

using namespace std;
int main()
{
    cout << Arge::nbYear(1500, 5, 100, 5000) << endl;
}