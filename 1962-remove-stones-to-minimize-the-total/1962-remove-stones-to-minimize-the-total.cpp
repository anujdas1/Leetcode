class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int> pq;

        int sum=0;

        for(int p:piles){
            pq.push(p);
            sum+=p;
        }

        for(int i=k; i>0; i--){
            int temp=pq.top()/2;
            sum-=temp;
            int temp2=pq.top()-temp;
            pq.pop();
            
            pq.push(temp2);

        }
        return sum;
    }
};