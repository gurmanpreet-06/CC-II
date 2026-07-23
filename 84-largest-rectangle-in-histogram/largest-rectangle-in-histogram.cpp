class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;

        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);

        // Previous Smaller Element (Left)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        // Clear stack before next pass
        while (!st.empty())
            st.pop();

        // Next Smaller Element (Right)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};