class Solution {
public:
    int compress(vector<char>& chars) {
        
        int n=chars.size();
        
        int j=0;
        for(int i=0;i<n;i++)
        {
            int count=1;
            while(i+1<n && chars[i]==chars[i+1])
            {
                count++;
                i++;
            }
            
            if(count==1) 
            {
                chars[j++]=chars[i];
            }
            else
            {
                chars[j++]=chars[i];
                for(char digit : to_string(count)) 
					chars[j++] = digit;
            }
        }
        
        return j;
    }
};