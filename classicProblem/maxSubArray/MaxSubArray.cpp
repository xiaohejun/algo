#include <iostream>
#include <vector>
#include <cassert>

#define on

#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x) ;
#endif

using namespace std;

class MaxSubArray
{
public:
    virtual int maxSubArray(vector<int>& nums) = 0;
};

class MaxSubArrayByDivideAndConquer
{
private:
    int findMaxCrossingSubarray(vector<int>& nums, int low, int mid, int high);
    int findMaxSubarray(vector<int> &nums, int low, int high);
public:
    int maxSubArray(vector<int>& nums);
};

int MaxSubArrayByDivideAndConquer::findMaxCrossingSubarray(vector<int>& nums, int low, int mid, int high)
{
    assert(high - low + 1 >= 2);

    assert(mid < nums.size());
    int leftMaxSum = nums[mid];
    int curSum = nums[mid];
    for (int i = mid - 1; i >= low; --i) {
        curSum += nums[i];
        leftMaxSum = max(leftMaxSum, curSum);
    }

    assert(mid + 1 < nums.size());
    int rightMaxSum = nums[mid + 1];
    curSum = nums[mid + 1];
    for (int i = mid + 2; i <= high; ++i) {
        curSum += nums[i];
        rightMaxSum = max(rightMaxSum, curSum);
    }

    return leftMaxSum + rightMaxSum;
}

int MaxSubArrayByDivideAndConquer::findMaxSubarray(vector<int> &nums, int low, int high)
{
    assert(low <= high);
    
    if (low == high) {
        return nums[low];
    }

    int mid = (low + high) / 2;
    int mx = findMaxSubarray(nums, low, mid);
    mx = max(mx, findMaxSubarray(nums, mid + 1, high));
    mx = max(mx, findMaxCrossingSubarray(nums, low, mid, high));

    return mx;
}

int MaxSubArrayByDivideAndConquer::maxSubArray(vector<int>& nums)
{
    return findMaxSubarray(nums, 0, nums.size() - 1);
}

class MaxSubArrayByDP
{
public:
    int maxSubArray(vector<int>& nums);
};

int MaxSubArrayByDP::maxSubArray(vector<int>& nums)
{
    int n = nums.size();
    int curMax = nums[0];
    int ans = curMax;
    for (int i = 1; i < n; ++i) {
        curMax = max(nums[i], curMax + nums[i]);
        ans = max(ans, curMax);
    }
    return ans;
}

int main()
{
    // 题目 https://leetcode.cn/problems/maximum-subarray/
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    MaxSubArrayByDP obj;
    dbg(obj.maxSubArray(nums))
    return 0;
}