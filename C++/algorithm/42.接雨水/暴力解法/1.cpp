#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n <= 2)
            return 0; // 少于3根柱子无法储水

        int total_water = 0;

        // 遍历每个柱子
        for (int i = 0; i < n; ++i)
        {
            int left_max = height[i]; // 初始化左边最大值为当前柱子高度
            // 向左遍历找左边最大值
            for (int j = i - 1; j >= 0; --j)
            {
                left_max = max(left_max, height[j]); // 更新左边最大值
            }

            int right_max = height[i]; // 初始化右边最大值为当前柱子高度
            // 向右遍历找右边最大值
            for (int j = i + 1; j < n; ++j)
            {
                right_max = max(right_max, height[j]); // 更新右边最大值
            }

            // 当前柱子积水量 = 左右最大值的较小者 - 当前高度
            int water = min(left_max, right_max) - height[i];
            if (water > 0)
            {
                total_water += water; // 累加有效积水量
            }
        }

        return total_water;
    }
};

