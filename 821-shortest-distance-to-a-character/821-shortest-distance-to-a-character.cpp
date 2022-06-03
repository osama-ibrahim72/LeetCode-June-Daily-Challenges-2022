class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        set<int>st;
        for(int i=0;i<s.size();i++){
            if (s[i]==c)
                st.insert(i);
        }
        vector<int>sol;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                sol.push_back(0);
            }else{
                int tmp = 1e9;
                for(auto v :st){
                    tmp = min(abs(i-v),tmp);
                }
                sol.push_back(tmp);
            }
        }
        return sol;
    }
};