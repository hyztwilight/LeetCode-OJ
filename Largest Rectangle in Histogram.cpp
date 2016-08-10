
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.size() == 0) return 0; 
        stack<int> st;
        int MAX = 0;
        height.push_back(0);
        int leftarea = 0, rightarea = 0;
        for(int i = 0; i < height.size(); ++i){
            while(!st.empty() && height[st.top()] > height[i]){
                int tmp = st.top();
                st.pop();
                leftarea = (st.empty() ? tmp + 1 : tmp - st.top()) * height[tmp]; //以tmp为高度，tmp所在柱以及向左延伸出来的矩形面积
                rightarea = (i - tmp - 1) * height[tmp]; //以tmp为高度，向右边延伸出来的矩形面积
                if((leftarea + rightarea) > MAX) MAX = (leftarea + rightarea);
            }
            st.push(i);
        }
        return MAX;
    }
};
/*
class Solution {
public:

    const int maxRectangle(vector<int>& heights, const int lhs, const int rhs){
        if(lhs==rhs)
            return heights[lhs];
        int middle=(lhs+rhs)>>1;
        
        int maxRec=0, maxRight=0;
        if(middle>lhs)
            maxRec=maxRectangle(heights, lhs, middle-1);
        maxRight=maxRectangle(heights, middle+1, rhs);
        maxRec=max(maxRight,maxRec);
        
        int middleMax=heights[middle];
        int minheight=heights[middle];
        int left=middle,right=middle;
        while(left>=lhs || right<=rhs){
            while(left>lhs && heights[left-1]>=minheight)
                left--;
            while(right<rhs && heights[right+1]>=minheight)
                right++;
            middleMax=max(middleMax, (right-left+1)*minheight);

            if(left>lhs && right<rhs){
                if(heights[left-1]>=heights[right+1]){
                    minheight=heights[left-1];
                    left--;
                }else{
                    minheight=heights[right+1];
                    right++;
                }
            }else if(left>lhs){
                minheight=heights[left-1];
                left--;
            }else if(right<rhs){
                minheight=heights[right+1];
                    right++;
            }else
                break;
        }
        
        return max(maxRec, middleMax);
        
    }
    int largestRectangleArea(vector<int>& heights) {
        const int len=heights.size();
        if(len==0)
            return 0;
            
        return maxRectangle(heights, 0, len-1);
    }
};*/