//https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for(auto c:tokens){
            if(isdigit(c[c.size()-1])){
                long long num=stoll(c);
                 cout<<num<<endl;
                 st.push(num);
            }
            else{
                if(st.size()<2)return st.top();
                 long long a=st.top();
                    st.pop();
                  long long b=st.top();
                    st.pop();
                if(c=="+"){
                   
                    st.push(a+b);
                }
                else if(c=="-"){
                    st.push(b-a);
                }
                else if(c=="*"){
                  
                    st.push(a*b);
                }
                else st.push(b/a);
            }
        }
        return st.top();
    }
};
