#pragma once
#include <vector>
//All questions are from chapter 1 and is inorder

struct pairs
{
    int x;
    int y;
};
bool isUnique(std::string string);
bool checkPermutation(std::string string1, std::string string2);
char *replaceSpace(char *buf, int realSize);
bool palindromPerm(std::string string1);
bool oneAway(std::string string1, std::string string2);
std::string stringCompression(std::string input);
void rotateMatrix(std::vector<std::vector<int>> &matrix);
void zeroMatrix(std::vector<std::vector<int>> &matrix);
bool stringRotation(std::string string1, std::string string2);
