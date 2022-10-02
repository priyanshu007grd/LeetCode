class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        list<string> res; //queue
        if(digits.size()==0) return vector<string>();
        vector<string> charmap{{"0"}, {"1"}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};

        res.push_back("");
        for(int i=0;i<digits.size();i++)
        {
            
            string charArr = charmap[digits[i]-'0'];
            int n=res.size();
            for(int k=0; k<n ;k++)
            {
                string front = res.front();
                res.pop_front();
                for(int j=0;j<charArr.size();j++) {
                    res.push_back(front+charArr[j]);
                }
            }
        }
        
        vector<string> result(res.begin(), res.end());
        return result;
    }
};