class Solution {
public:
    int minDeletions(string s) {
        vector<int>arr(26);
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        sort(arr.begin(),arr.end());
        int sol =0;
        map<int,int>mp;
        for(int i=0;i<26;i++){
            if(arr[i]>0){
                if(mp[arr[i]]==0){
                    mp[arr[i]]=1;
                }else{
                    int tmp = arr[i];
                    for(tmp;tmp>0;tmp--){
                        if(mp[tmp]==0){
                            mp[tmp]=1;
                            break;
                        }
                    }
                    sol+=arr[i]-tmp;
                }
            }
        }
        return sol;
    }
};