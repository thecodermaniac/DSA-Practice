#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int> pair1, pair<int, int> pair2)
{
    float r1 = pair1.first / pair1.second;
    float r2 = pair2.first / pair2.second;
    return r1 > r2;
}

float max_value(vector<pair<int, int>> vec, int weight)
{
    sort(vec.begin(), vec.end(), cmp);
    int curr_weight = 0;
    float final_res = 0.0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (curr_weight + vec[i].second <= weight)
        {
            curr_weight += vec[i].second;
            final_res += vec[i].first;
        }
        else
        {
            int remain = weight - curr_weight;
            final_res += ((float)remain / (float)vec[i].second) * vec[i].first;
            break;
        }
    }
    return final_res;
}
int main(int argc, char const *argv[])
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < 3; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        vec.push_back(make_pair(temp1, temp2));
    }
    cout << "the max no of units of knapsack is " << max_value(vec, 50);
    return 0;
}
