#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> dym;
    for (int i = 0; i < 4; i++)
    {
        dym.push_back(i);
    }
    for (auto i = dym.begin(); i != dym.end(); i++)
    {
        cout << *i;
    }
    cout << *dym.begin();
    return 0;
}