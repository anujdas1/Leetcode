class Solution {
public:
    bool canAliceWin(int n) {
        int curr=10;
        int count=0;
        while(n>=curr){
            n-=curr;
            curr--;
            count++;
        }
        return count%2?true:false;
    }
};