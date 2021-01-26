class Solution {
private:
    int largestRectangleAreaDivideAndConquer(vector<int>& heights, int start, int end) {
        if (start > end) {
            return 0;
        }

        int minIdx = start;
        for (int i = start; i <= end; ++i) {
            if (heights[minIdx] > heights[i]) {
                minIdx = i;
            }
        }

        return max({
            heights[minIdx] * (end - start + 1),
            largestRectangleAreaDivideAndConquer(heights, start, minIdx - 1),
            largestRectangleAreaDivideAndConquer(heights, minIdx + 1, end)
        });
    }

    int largestRectangleAreaStack(vector<int>& heights) {
        stack<int> heightsStack;
        int maxArea = numeric_limits<int>::min();

        for (size_t i = 0; i < heights.size(); ++i) {
            while (!heightsStack.empty() && heights[heightsStack.top()] > heights[i]) {
                int height = heights[heightsStack.top()];
                heightsStack.pop();
                int width = heightsStack.empty() ? i : i - heightsStack.top() - 1;

                maxArea = max(maxArea, height * width);
            }
            heightsStack.push(i);
        }

        while (!heightsStack.empty()) {
            int height = heights[heightsStack.top()];
            heightsStack.pop();
            int width = heightsStack.empty() ? heights.size() : heights.size() - heightsStack.top() - 1;

            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        return largestRectangleAreaStack(heights);
    }
};
