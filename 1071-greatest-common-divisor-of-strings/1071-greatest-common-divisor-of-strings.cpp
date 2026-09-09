class Solution {
public:
    int GCD(int n, int m){
        while(n!=0 && m!=0){
            int temp=min(n, m);
            n=abs(n-m);
            m=temp;
        }

        if(n==0) return m;
        return n;
    }
    string gcdOfStrings(string str1, string str2) {
        if((str1+str2)!=(str2+str1)) return "";

        int gcdLength=GCD(str1.length(), str2.length());

        return str1.substr(0, gcdLength);
    }
};