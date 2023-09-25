#include <vector>
#include <iostream>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr)
    {
        for (int k = 0; k <= 1; k++)
        {
            for (int i = 1; i < arr.size(); i++)
            {
                if ((arr[i] == "NORTH" && arr[i - 1] == "SOUTH") ||
                    (arr[i] == "SOUTH" && arr[i - 1] == "NORTH") ||
                    (arr[i] == "EAST" && arr[i - 1] == "WEST") ||
                    (arr[i] == "WEST" && arr[i - 1] == "EAST"))
                {
                    arr[i] = "";
                    arr[i - 1] = "";
                    k = 0;
                }
            }
            for (auto i = --arr.end(); i >= arr.begin(); i--)
            {
                if (*i == "")
                    arr.erase(i);
            }
        }
        return arr;
    }
};

int main()
{
    std::vector<std::string> d = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
    for (auto &&item : DirReduction::dirReduc(d))
    {
        std::cout << item << "\n";
    }
}