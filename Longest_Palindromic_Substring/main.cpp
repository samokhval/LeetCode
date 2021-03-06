#include <QDebug>
#include <string>
#include <iostream>

using namespace std;
//"caba"
string searchPalindrome(string s)
{
    int len = s.length();
    string newStr = "$#";

    for(int i=0; i<len; i++)
    {
        newStr += s[i];
        newStr += "#";
    }

    newStr += '\0';

    return newStr;
}

string longestPalindrome(string s)
{
    string newStr= searchPalindrome(s);

    int len = newStr.length();
    int mx = 0;
    int id = 1;
    int first = 0;
    int maxlen = 0;

    int *pi = new int[len];
    pi[0]=0;

    for(int i=1; i<len; i++)
    {
        if(mx>i)
        {
            pi[i]=min(pi[2*id-i],mx-i);
        }
        else
            pi[i]=1;

        while(newStr[pi[i]+i] == newStr[i-pi[i]])
            pi[i]++;

        if((pi[i]+i)>mx)
        {
            mx=pi[i]+i;
            id=i;
        }

        if(maxlen<(2*pi[i]-2))
        {
            maxlen=2*pi[i]-2;
            first=i-pi[i]+1;
        }
    }

    string strMax(maxlen,'a');

    for(int i=0; i<maxlen; i++)
       strMax[i] = newStr[i+first];

    string resultStr;
    for(unsigned int i=0; i<strMax.length();i++)
    {
        if(strMax[i]!='#' && strMax[i]!='$')
        {
            resultStr+=strMax[i];
        }
    }
    return resultStr;
}

int main()
{
    string startValue = "caba";
    cout << "Start string:" << startValue << endl;
    cout << "Longest palindrome:" << longestPalindrome(startValue) << endl;
    return 0;
}

