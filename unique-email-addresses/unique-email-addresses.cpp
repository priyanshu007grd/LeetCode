class Solution {
public:
    int numUniqueEmails(vector<string>& emails) 
    {
        set<string> s;
        for(auto email:emails)
        {
            string localName="";
            string domain="";

            for(int i=0;i<email.size();i++)
            {
                if(email[i]=='+' || email[i]=='@') break;
                else if(email[i]!='.') localName+=email[i];
            }
            for(int i=email.size()-1;i>=0;i--)
            {
                if(email[i]=='@') break;
                else domain+=email[i];
            }

            s.insert(localName+domain);
        }

        return s.size();
    }
};