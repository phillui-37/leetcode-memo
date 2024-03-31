#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if (n == 0) return;
        int i=0, j=0;
        for (;i<m+n;)
        {
            if (i >= m)
            {
                nums1[i++] = nums2[j++];
            }
            else if (nums1[i] > nums2[j])
            {
                swap(nums1[i], nums2[j]);
                for (int k=j;k<n-1 && nums2[k] > nums2[k+1];k++)
                    swap(nums2[k], nums2[k+1]);
                i++;
            }
            else
                i++;
        }
    }
};

int main(int argc, char const *argv[])
{
    using t_param = tuple<vector<int>, int, vector<int>, int>;
    vector<t_param> params = {
        make_tuple(vector<int> {1,2,3,0,0,0}, 3, vector<int> {2,5,6}, 3),
        make_tuple(vector<int> {1}, 1, vector<int> {}, 0),
        make_tuple(vector<int> {0}, 0, vector<int> {1}, 1),
        make_tuple(vector<int> {1,2,4,4,5,0,0,0,0},5, vector<int>{2,3,4,5}, 4),
    };
    vector<vector<int>> results = {
        {1,2,2,3,5,6},
        {1},
        {1},
        {1,2,2,3,4,4,4,5,5}
    };
    for (unsigned i=0;i<params.size();i++)
    {
        auto param = params[i];
        auto result = results[i];
        Solution().merge(get<0>(param), get<1>(param), get<2>(param), get<3>(param));
        cout << i
             << "'s pair result: "
             << (get<0>(param) == result ? "valid" : "unvalid")
             << endl;
    }
    
    return 0;
}
