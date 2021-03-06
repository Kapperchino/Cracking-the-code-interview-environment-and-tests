#include <iostream>
#include "array.hpp"
#include <string>
#include <unordered_set>

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
        if (charArray[x])
        {
            output += char(x);
            output += std::to_string(charArray[x]);
        }
    }
    return output;
}

void rotateMatrix(std::vector<std::vector<int>> &matrix)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return;
    }

    int temp = 0;
    int offset = 0;
    for (int layer = 0; layer < matrix.size() / 2; layer++)
    {
        int last = matrix.size() - 1 - layer;
        int first = layer;
        for (int x = first; x < last; x++)
        {
            //make sure to do this b/c you need to keep track of which layer you are in
            offset = x - layer;
            temp = matrix[layer][x];
            //top and left
            matrix[first][x] = matrix[last - offset][first];
            //left and bottom
            matrix[last - offset][first] = matrix[last][last - offset];
            //bottom and right
            matrix[last][last - offset] = matrix[x][last];
            //right and top
            matrix[x][last] = temp;
        }
    }
}

void zeroMatrix(std::vector<std::vector<int>> &matrix)
{
    if (matrix.size() == 0)
    {
        return;
    }

    std::unordered_set<int> setX;
    std::unordered_set<int> setY;
    for (int x = 0; x < matrix.size(); x++)
    {
        for (int y = 0; y < matrix.size(); y++)
        {
            if (matrix[x][y] == 0)
            {
                setX.insert(x);
                setY.insert(y);
            }
        }
    }
    auto itr2 = setY.begin();
    for (auto itr = setX.begin(); itr != setX.end(); ++itr)
    {
        //sets rows
        for (int y = 0; y < matrix[*itr].size(); y++)
        {
            matrix[*itr][y] = 0;
        }
        //sets colum
        for (int x = 0; x < matrix.size(); x++)
        {
            matrix[x][*itr2] = 0;
        }
        ++itr2;
    }
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
                break;

        if (j == M)
            return true;
    }

    return false;
}

bool stringRotation( std::string string1,  std::string string2)
{
    if (string1.length() != string2.length())
    {
        return false;
    }
    string1 += string1;
    return isSubstring(string2,string1);
}
