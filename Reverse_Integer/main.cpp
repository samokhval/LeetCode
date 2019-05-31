#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int reverse(int x)
{
    long long int result = 0;
    int count = std::to_string(x).size();

    if (x < 0)
    {
        count--;
    }

    for (int i = count-1; i >= 0; i--)
    {
        long long int tmp = (x % 10);
        tmp = tmp * pow(10,i);
        x /= 10;
        result += tmp;
    }

    if ((result > pow(2,31) - 1) || (result < pow(-2,31)))
        return 0;
    else
        return result;
}

int main()
{
    int x = 15342369;

    int result = reverse(x);

    cout << "result = " << result << endl;

    return 0;
}

