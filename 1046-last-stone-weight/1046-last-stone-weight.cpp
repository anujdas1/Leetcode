class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int s:stones){
            pq.push(s);
        }
        // int ans=0;
        while(!pq.empty()){
            int a=pq.top();
            pq.pop();
            if(pq.empty()){
                return a;
            }
            int b=pq.top();
            pq.pop();
            pq.push(abs(a-b));
        }

        return 0;
    }
};