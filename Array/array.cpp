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

bool palindromPerm(std::string string1)
{
    if (string1.empty())
    {
        return false;
    }
    int Oddsum = 0;
    int alphabetArr[128] = {0};
    for (int x = 0; x < string1.length(); x++)
    {
        if (string1[x] != ' ')
        {
            alphabetArr[string1[x]]++;
        }
    }

    for (int x = 0; x < 128; x++)
    {
        if (alphabetArr[x] % 2 == 1)
        {
            Oddsum++;
        }
    }
    //can only have one odd
    if (Oddsum > 1)
    {
        return false;
    }
    return true;
}

bool oneAway(std::string string1, std::string string2)
{
    if (std::abs(string1.length() - string2.length() > 1))
    {
        return false;
    }
    int length = 0;
    int diffCount = 0;
    int index = 0;
    std::string *str1Ptr = nullptr;
    std::string *str2Ptr = nullptr;
    if (string1.length() < string2.length())
    {
        length = string2.length();
        str1Ptr = &string2;
        str2Ptr = &string1;
    }
    else
    {
        length = string1.length();
        str1Ptr = &string1;
        str2Ptr = &string2;
    }

    for (int x = 0; x < length; x++)
    {
        if ((*str1Ptr)[index] != (*str2Ptr)[x])
        {
            ++diffCount;
            if (string1.length() != string2.length())
            {
                index++;
            }
        }
        ++index;
    }
    if (diffCount != 1)
    {
        return false;
    }
    return true;
}

std::string stringCompression(std::string input)
{
    if (input.empty())
    {
        return input;
    }
    int charArray[128] = {0};
    std::string output;
    for (int x = 0; x < input.length(); x++)
    {
        charArray[input[x]]++;
    }
    for (int x = 0; x < 128; x++)
    {
        if(charArray[x])
        {
            output+= char(x);
            output+= std::to_string(charArray[x]);
        }
    }
    return output;
}
