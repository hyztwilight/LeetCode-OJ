class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty())
            return 0;
        vector<int> h(matrix.size()+1, 0);
        int ans = 0;
        for(int i=0;i<matrix[0].size();i++){
            stack<int> s;
            for(int j=0;j<matrix.size();j++){
                h[j] = 0;
                for(int t=i;t<matrix[0].size();t++)
                    if(matrix[j][t]=='0') break;
                    else h[j]++;
            }
            for(int j=0;j<h.size();j++){
                while(!s.empty() && h[j] < h[s.top()]){
                    int tmp = s.top();
                    s.pop();
                    int lhs = (s.empty() ? tmp+1 : tmp-s.top())*h[tmp];
                    int rhs = (j-tmp-1)*h[tmp];
                    if((tmp=lhs+rhs) > ans) ans = tmp;
                }
                s.push(j);
            }
        }
        return ans;
    }
};