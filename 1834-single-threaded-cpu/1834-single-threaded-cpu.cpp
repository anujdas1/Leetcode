class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<vector<int>> sortedTasks;
        for(int i=0; i<n; i++){
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(sortedTasks.begin(), sortedTasks.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        int idx=0;
        long long curr_time=0;
        vector<int> ans;

        while(idx<n || !pq.empty()){
            if(pq.empty() && curr_time<sortedTasks[idx][0]){
                curr_time=sortedTasks[idx][0];
            }

            while(idx<n && sortedTasks[idx][0]<=curr_time){
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }

            pair<int,int> curr_el=pq.top();
            pq.pop();
            curr_time+=curr_el.first;
            ans.push_back(curr_el.second);
        }

        return ans;
    }
};