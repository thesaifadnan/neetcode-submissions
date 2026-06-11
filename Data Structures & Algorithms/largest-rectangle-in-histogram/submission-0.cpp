class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, n = heights.size();
        vector<int>leftMin(n,-1);
        vector<int>rightMin(n,n);

        stack<int>lst;
        stack<int>rst;
        for(int i=0;i<n;i++){
            while(!lst.empty() && heights[lst.top()] >= heights[i]){
                lst.pop();
            }

            if(!lst.empty()){
                leftMin[i] = lst.top();
            }
            lst.push(i);

            while(!rst.empty() && heights[rst.top()] >= heights[n-i-1]){
                rst.pop();
            }

            if(!rst.empty()){
                rightMin[n-i-1] = rst.top();
            }
            rst.push(n-i-1);
        }

        for(int i=0;i<n;i++){
            int area = ((rightMin[i]-leftMin[i])-1) * heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
