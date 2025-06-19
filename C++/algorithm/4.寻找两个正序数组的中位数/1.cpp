#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // 确保nums1是较短的数组，减少二分次数
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m + n + 1) / 2; // 左半部分的总长度（中位数位置）

        // 在nums1的区间[0, m]中寻找合适的分割点i
        int imin = 0, imax = m;
        while (imin <= imax)
        {
            int i = (imin + imax) / 2; // nums1的分割点，左边有i个元素
            int j = totalLeft - i;     // nums2的分割点，左边有j个元素

            // 处理边界情况：当i=0时，nums1左半部分为空，比较时跳过nums1
            int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
            // 同理处理nums2的边界情况
            int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

            if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin)
            {
                // 找到正确的分割点，计算中位数
                if ((m + n) % 2 == 1)
                { // 总长度为奇数，取左半部分最大值
                    return max(nums1LeftMax, nums2LeftMax);
                }
                else
                { // 总长度为偶数，取左最大和右最小的平均
                    return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
                }
            }
            else if (nums1LeftMax > nums2RightMin)
            {
                // i太大，需要减小i的范围，向左调整
                imax = i - 1;
            }
            else
            {
                // i太小，需要增大i的范围，向右调整
                imin = i + 1;
            }
        }
        return 0.0;
    }
};

