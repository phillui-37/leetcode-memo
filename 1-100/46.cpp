#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * this can be done by extract one entry of variable
     * then call self recurisivly providing sublist except the extracted one until the variable is empty
    */
    vector<vector<int>> permute(vector<int>& nums)
    {
        if (nums.size() == 0) return {};

        vector<vector<int>> result;

        for (int i=0;i<nums.size();i++)
        {
            vector<int> param(nums.cbegin(), nums.cbegin()+i);
            param.insert(param.end(), nums.cbegin()+i+1,nums.cend());

            vector<vector<int>> otherCombinations = permute(param);
            if (otherCombinations.size() == 0)
                return {{nums[i]}};
            for (int j=0;j<otherCombinations.size();j++)
            {
                vector<int> row = {nums[i]};
                row.insert(row.end(), otherCombinations[j].cbegin(), otherCombinations[j].cend());
                result.push_back(row);
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    auto obj = Solution();
    return 0;
}
