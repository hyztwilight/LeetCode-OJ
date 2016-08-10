class Solution {
public:
    const bool crossing(vector<int>& x, const int index){
        if( (x[index-1]+x[index-5])<x[index-3] || x[index-2]<x[index-4] ){
            if(x[index]>=x[index-2])
                return true;
        }else if(x[index-1]<=x[index-3]){
            if( x[index]>=(x[index-2]-x[index-4]) )
                return true;
        }
        return false;
    }
    bool isSelfCrossing(vector<int>& x) {
        if(x.size()<4)
            return false;
        if(x[0]>=x[2]&&x[1]<=x[3])
            return true;
        if(x.size()==5){
            if(x[3]==x[1] && (x[0]+x[4])>=x[2])
                return true;
            if(x[3]<x[1] && x[4]>=x[2])
                return true;
        }
        for(int i=5;i<x.size();i++)
            if(crossing(x,i))
                return true;
        return false;
    }
};
