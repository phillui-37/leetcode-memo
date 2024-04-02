#include <vector>
#include <tuple>
#include <cassert>
#include <iostream>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int sameCount = 0;
        for (int i = 0; i < nums.size() - sameCount; i++)
        {
            if (nums[i] == val)
            {
                swap(nums[i], nums[nums.size() - 1 - sameCount]);
                sameCount++;
                i--;
            }
        }
        return nums.size() - sameCount;
    }
};

int main(int argc, char const *argv[])
{
    using t_param = tuple<vector<int>, int>;

    vector<t_param> params{
        {vector<int>{3, 2, 2, 3}, 3},
        {vector<int>{0, 1, 2, 2, 3, 0, 4, 2}, 2}};

    vector<t_param> expects{
        {vector<int>{2, 2, -1, -1}, 2},
        {vector<int>{0, 1, 4, 0, 3, -1, -1, -1}, 5}};

    auto sol = Solution();

    for (int i = 0; i < params.size(); i++)
    {
        cout << i << " testing start" << endl;
        auto param = params[i];
        auto expect = expects[i];
        int count = sol.removeElement(get<0>(param), get<1>(param));
        assert((get<1>(expect) == count));
        auto resultToCompare = vector<int>(get<0>(param).begin(), get<0>(param).begin() + get<1>(expect));
        auto expectToCompare = vector<int>(get<0>(expect).begin(), get<0>(expect).begin() + get<1>(expect));
        assert((expectToCompare == resultToCompare));
        cout << i << " testing done" << endl;
    }

    return 0;
}
