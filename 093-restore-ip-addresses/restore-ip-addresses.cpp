// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
// Example:
//
//
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]
//
//


class Solution {
public:
    //我们需要IP地址的规则。1.0.0.1~255.255.255.255
    //我们先进行分割，求得所有的ip组合25/52/55/11135
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        vector<string> before;
        getAIp(s,0,s.size(),4,before,result);
        return result;
    }
    
    //
    void getAIp(string& s,int begin,int end,int num_left,vector<string>&before,vector<string>& result)
    {
        //if(begin>end) return;
        if(num_left==0)//选了4个ip
        {
            if(begin!=end) 
            {
                return;//有剩余字母               
            }                
            else
            {
                string answer;
                for(auto &elem:before)
                    answer+=elem+".";
                answer.pop_back();
                result.push_back(answer);              
            }
        }

        string str;
        for(int i=0;begin+i<end&&i<3;++i)//255
        {
            str=s.substr(begin,i+1);
            if(stoi(str)<0||stoi(str)>255||(str.size()>1&&str[0]=='0'))
                continue;           
            before.push_back(str);
            getAIp(s,begin+i+1,end,num_left-1,before,result);
            before.pop_back(); 
            str.clear();
        }
        
    }
};
