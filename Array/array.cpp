#include <iostream>
#include "array.hpp"
#include <string>
#include <unordered_set>

bool isUnique(std::string string)
{
    return false;
}

bool checkPermutation(std::string string1, std::string string2)
{
    return false;
}

char *replaceSpace(char *string, int realSize)
{
    return "";
}

bool palindromPerm(std::string string1)
{
    return false;
}

bool oneAway(std::string string1, std::string string2)
{
    return false;
}

std::string stringCompression(std::string input)
{
    return "";
}

void rotateMatrix(std::vector<std::vector<int>> &matrix)
{
    return;
}

void zeroMatrix(std::vector<std::vector<int>> &matrix)
{
    return;
}

//helper function(copied from geeks for geeks)
static bool isSubstring(std::string string1, std::string string2)
{
    if (!string1.empty() || !string2.empty())
    {
        return true;
    }
    int M = string1.length();
    int N = string2.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (string1[i + j] != string2[j])
                break; if (string1.length() != string2.length())
    {
        return false;
    }
    string1 += string1;
    return isSubstring(string2,string1);

        if (j == M)
            return true;
    }

    return false;
}

bool stringRotation(std::string string1, std::string string2)
{
    return false;
}
