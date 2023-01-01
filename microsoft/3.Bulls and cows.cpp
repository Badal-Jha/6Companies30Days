//
// first approch
class Solution {
public:
    string getHint(string secret, string guess) {
        int cnt=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])cnt++;
        }

        int cnt2=0;
        map<char,int>mp;
        for(auto c:secret)mp[c]++;
        
        for(int i=0;i<guess.size();i++){
            if(mp[guess[i]]){
                cnt2++;
                mp[guess[i]]--;
            }
        }
        cnt2-=cnt;
        string ans=to_string(cnt)+"A"+to_string(cnt2)+"B";
        return ans;
    }
};

//more optimized
class Solution {
public:
    string getHint(string secret, string guess) {
          int cnt=0;
         int cnt2=0;
        vector<int>hash(10,0);
        for(int i=0;i<secret.size();i++){
            
            if(secret[i]==guess[i])cnt++;
            else{ 
               if(hash[secret[i]-'0']<0)cnt2++;
               if(hash[guess[i]-'0']>0)cnt2++;

               hash[secret[i]-'0']++;
               hash[guess[i]-'0']--;
            }
            }
        
        
       
       
        string ans=to_string(cnt)+"A"+to_string(cnt2)+"B";

        return ans;
    }
};
