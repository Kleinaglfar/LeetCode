#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dpv{};
        dpv=triangle[triangle.size()-1];
        vector<int> dpc{};
        int counter=triangle.size()-1;
        for(int i=1;i<triangle.size();i++){
            for(int j=0;j<counter;j++){
                dpc.push_back(min(dpv[j],dpv[j+1])+triangle[triangle.size()-i-1][j]);
            }
                counter--;
            dpv=dpc;
            dpc.clear();
        }
        return dpv[0];
        
    }
};