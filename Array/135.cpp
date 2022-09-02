#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()<=1) return ratings.size();
        if(ratings.size()==2){
            if(ratings[0]==ratings[1]) return 2;
            else return 3;
        }
        vector<int> down{};
        if(ratings[1]>=ratings[0]) down.push_back(0);
        for(int i=1;i<ratings.size()-1;i++){
            if(ratings[i-1]>=ratings[i]&&ratings[i+1]>=ratings[i])
                down.push_back(i);
        }
        if(ratings[ratings.size()-1]<=ratings[ratings.size()-2]) down.push_back(ratings.size()-1);
        vector<int> res(ratings.size(),0);
        for(int i=0;i<down.size();i++){
            helper(down[i],ratings,res);
        }
        int trueres=0;
        for(auto i:res){
            trueres+=i;
        }
        return trueres;
    }
    void helper(int index,vector<int>& ratings,vector<int>& res){
        res[index]=1;
        int pointer=index-1;
        while(pointer>=0&&ratings[pointer]>ratings[pointer+1]){
            if(res[pointer]!=0){
                res[pointer]=max(res[pointer],res[pointer+1]+1);
                break;
            }
            else{
                res[pointer]=res[pointer+1]+1;
            }
            pointer--;
        }
        pointer=index+1;
        while(pointer<ratings.size()&&ratings[pointer]>ratings[pointer-1]){
            if(res[pointer]!=0){
                res[pointer]=max(res[pointer],res[pointer-1]+1);
                break;
            }
            else{
                res[pointer]=res[pointer-1]+1;
            }
            pointer++;
        }
    }
};