#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;
class material
{
    map<string, int> form;

public:
    material(string formstr)
    {
        string elem;
        string index;
        istringstream line(formstr);
        while (line >> elem)
        {
            line >> index;
            this->form[elem] = stoi(index);
        }
    }
};

vector<int> Format(vector<material> &in, vector<material> &out)
{
    vector<int> amount;
    amount.resize(in.size() + out.size());
}

int main()
{
    vector<material> input, output;
    string f;
    cout << "input:\n";
    while (true)
    {
        getline(cin, f);
        if (f == "")
            break;
        input.push_back(material(f));
    }
    cout << "output:\n";
    while (true)
    {
        getline(cin, f);
        if (f == "")
            break;
        output.push_back(material(f));
    }
    Format(input, output);
    return 0;
}