#include <iostream>
#include "array.hpp"
#include <string>

bool isUnique(std::string string)
{
    if (string.empty())
    {
        return false;
    }
    //one bool per character
    bool charCheck[128] = {false};
    for (int x = 0; x < string.length(); x++)
    {
        if (charCheck[string[x]] == true)
        {
            return false;
        }
        charCheck[string[x]] = true;
    }
    return true;
}

bool checkPermutation(std::string string1, std::string string2)
{
    if (string1.empty() || string2.empty())
    {
        return true;
    }
    if (string1.length() != string2.length())
    {
        return false;
    }
    int numChars[128] = {0};
    for (int x = 0; x < string1.length(); x++)
    {
        numChars[string1[x]]++;
        numChars[string2[x]]--;
    }

    for (int x = 0; x < 128; x++)
    {
        if (numChars[x] != 0)
        {
            return false;
        }
    }
    return true;
}

char *replaceSpace(char *string, int realSize)
{
    if (!string)
    {
        return NULL;
    }
    int spaceCount = 0;
    int index = 0;
    for (int x = 0; x < realSize; x++)
    {
        if (string[x] == ' ')
        {
            spaceCount++;
        }
    }
    index = realSize + spaceCount * 2 - 1;
    for (int x = realSize - 1; x >= 0; x--)
    {
        if (string[x] == ' ')
        {
            string[index] = '0';
            string[index - 1] = '2';
            string[index - 2] = '%';
            index -= 3;
        }
        else
        {
            string[index] = string[x];
            index--;
        }
    }
    return string;
}

static void shiftBuf(char *arr, int size, int pos, int amount)
{
    for (int x = pos; x < size - amount; x++)
    {
        arr[x + amount] = arr[x];
    }
}
