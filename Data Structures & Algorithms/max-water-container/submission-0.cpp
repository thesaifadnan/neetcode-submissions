class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int maxSize = 0;
        while(left<right){
            maxSize = max(maxSize, (right-left) * min(heights[left],heights[right]));
            if(heights[right] <= heights[left]){
                right--;
            }else{
                left++;
            }
        }

        return maxSize;
    }
};
