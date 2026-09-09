class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        string ans="";

        int l=0, r=0;

        while(l<n && r<m){
            if((l+r)%2==0) {
                ans+=word1[l];
                l++;
            }else{
                ans+=word2[r];
                r++;
            }
        }

        while(l<n){
            ans+=word1[l];
            l++;
        }
        while(r<m){
            ans+=word2[r];
            r++;
        }

        return ans;
    }
};