#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string convert(std::string s, int numRows)
{
    if (numRows == 1) return s;

    int curRow = 0;
    bool goingDown = false;
    std::vector<std::string> rows(numRows);

    for (char c : s)
    {
        rows[curRow] += c;
 
        if (curRow == 0 || curRow == numRows - 1)
        {
            goingDown = !goingDown;
        }
        curRow += goingDown ? 1 : -1;
    }

    std::string retString;
    for (std::string row : rows) retString += row;
    return retString;
}

int main()
{
    using namespace std;

    string inputStr = "PAYPALISHIRING";
    cout << "Input string: " << inputStr << endl;
    string outputStr = convert(inputStr, 4);
    cout << "Output string: " << outputStr << endl;

    return 0;
}

