#include <string>

class numstring
{
private:
    std::string value;

public:
    numstring(std::string n);
    numstring operator+(numstring other);
};

class numstringexception : std::exception
{
};