#include <bits/stdc++.h>
using namespace std;

vector<string> dialpad = {"", "", "abc", "def", "ghi", "jki", "mno", "pqrs", "tuv", "wxyz"};

void letterCombinations(string &input, string &strSofar, vector<string> &result, int start, int end)
{
// Base 
if (start > end)
{
result.push_back(strSofar);
return;
}
else
{
char digitPressed = input[start]; 
string possibleMoves = dialpad[digitPressed - '0'];

for (int i = 0; i < possibleMoves.size(); i++)
{
strSofar.push_back(possibleMoves[i]);

letterCombinations(input, strSofar, result, start + 1, end);
strSofar.pop_back();
}
}
}

vector<string> generateParenthesis(string &input)
{
    vector<string> result;
    int start = 0, end = input.size() - 1;
    string strSoFar = "";
    letterCombinations(input, strSoFar, result, start, end);
    return result;
}

int main() {

    return 0;
}