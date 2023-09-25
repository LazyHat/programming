#include <string>

using namespace std;
string DNAStrand(const string &dna)
{
    string s = dna;
    for (auto &sym : s)
    {
        if (sym == 'T')
            sym = 'A';
        if (sym == 'A')
            sym = 'T';
        if (sym == 'G')
            sym = 'C';
        if (sym == 'C')
            sym = 'G';
    }
    return s;
}

int main()
{
}