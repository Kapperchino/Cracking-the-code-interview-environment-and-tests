#include <iostream>
#include "array.hpp"
#include <string>

bool isUnique(std::string string)
{
    if (string.empty())
    {
        return false;
    }
    //checks for
    bool charCheck[128];
    for (int x = 0; x < string.length(); x++)
    {
        if (charCheck[string[x]] == true)
        {
            return false;
        }
        charCheck[x] = true;
    }
    return true;
}