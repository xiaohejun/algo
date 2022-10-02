#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

// #define on

#ifdef on
#define dbg(x) cout << "line-(" << __LINE__ << "): " << #x"=" << x << endl;
#else
#define dbg(x) ;
#endif

class ReversePairs
{
public:
    virtual int reversePairs(vector<int>& nums) = 0;
};

class MergeSortReversePairs : public ReversePairs
{
private:
    int merge(vector<int>& nums, int l, int mid, int r);
    int reversePairs(vector<int>& nums, int l, int r);
public:
    int reversePairs(vector<int>& nums);
};

int MergeSortReversePairs::merge(vector<int>& nums, int l, int mid, int r)
{
    dbg("-----------")
    dbg(l)
    dbg(mid)
    dbg(r)
    int n1 = mid - l + 1;
    vector<int> a(n1);
    for (int i = 0; i < n1; ++i) {
        a[i] = nums[l + i];
    }

    int n2 = r - mid;
    vector<int> b(n2);
    for (int i = 0; i < n2; ++i) {
        b[i] = nums[mid + 1 + i];
    }

    int revPairNum = 0;
    int i = 0;
    int j = 0;
    for (int k = l; k <= r; ++k) {
        if (i >= n1) {
            nums[k] = b[j];
            ++j;
        } else if (j >= n2) {
            nums[k] = a[i];
            ++i;
        } else {
            // i < n1 && j < n2
            if (a[i] <= b[j]) {
                nums[k] = a[i];
                ++i;
            } else { // a[i] > b[j]
                nums[k] = b[j];
                ++j;

                /* 
                当前 a[i] > b[j]，那么a[i .... n1 - 1] 都能和 b[j] 组成逆序对
                a[i .... n1 - 1]一共(n1 - 1 - i + 1) = (n1 - i)个元素
                */ 
                revPairNum += (n1 - i);
                dbg(i)
            }
        }
    }

    dbg(revPairNum)
    dbg("-----------")
    return revPairNum;
}

int MergeSortReversePairs::reversePairs(vector<int>& nums, int l, int r)
{
    if (l >= r) {
        return 0;
    }

    int mid = (l + r) / 2;

    int revPairNum = 0;
    revPairNum += reversePairs(nums, l, mid);
    revPairNum += reversePairs(nums, mid + 1, r);
    revPairNum += merge(nums, l, mid, r);

    dbg(l)
    dbg(r)
    dbg(revPairNum)
    return revPairNum;
}

int MergeSortReversePairs::reversePairs(vector<int>& nums)
{
    int ans = reversePairs(nums, 0, nums.size() - 1);
    for (int x : nums) {
        dbg(x)
    }
    return ans;
}

int main()
{
    /*
    测试用例：
    https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
    */
    MergeSortReversePairs obj;
    vector<int> nums = {233,2000000001,234,2000000006,235,2000000003,236,2000000007,237,2000000002,2000000005,233,233,233,233,233,2000000004};
    cout << obj.reversePairs(nums) << endl;
    return 0;
}