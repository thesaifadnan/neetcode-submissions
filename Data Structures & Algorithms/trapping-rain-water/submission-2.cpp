class Solution {
public:
    int trap(vector<int>& height) {
        int area =0,n=height.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        int leftMax= height[0], rightMax = height[n-1];
        for(int i=1;i<n-1;i++){

            if(height[i]>leftMax){
                left[i] = 0;
                leftMax = height[i];
            }else{
                left[i] = leftMax;
            }

            if(rightMax > height[n-i-1]){
                right[n-i-1] = rightMax;
            }else{
                right[n-i-1]= 0;
                rightMax = height[n-i-1];
            }

        }

        for(int i=1;i<n-1;i++){
            area += min(left[i],right[i]) > height[i]? min(left[i],right[i]) - height[i]:0;
        }
        return area;
    }
};
