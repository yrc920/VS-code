#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> stk; // 单调栈，存储柱子的索引，保持对应高度递增
        int max_area = 0;

        // 遍历每个柱子，确定其右边界并计算面积
        for (int i = 0; i < n; ++i)
        {
            // 当当前柱子高度小于栈顶柱子的高度时，说明找到栈顶柱子的右边界
            while (!stk.empty() && heights[i] < heights[stk.top()])
            {
                int top_idx = stk.top(); // 弹出栈顶元素
                stk.pop();
                // 左边界为当前栈顶元素（若栈为空则为-1）
                int left = stk.empty() ? -1 : stk.top();
                int width = i - left - 1;            // 计算宽度
                int area = heights[top_idx] * width; // 计算当前面积
                max_area = max(max_area, area);      // 更新最大面积
            }
            stk.push(i); // 将当前柱子索引入栈
        }

        // 处理栈中剩余的柱子，它们的右边界为n
        while (!stk.empty())
        {
            int top_idx = stk.top();
            stk.pop();
            int left = stk.empty() ? -1 : stk.top();
            int width = n - left - 1; // 右边界为n，宽度计算
            int area = heights[top_idx] * width;
            max_area = max(max_area, area);
        }

        return max_area;
    }
};