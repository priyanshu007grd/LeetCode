class Solution 
{
public:
    int ans;
    vector<int> pTime;
    int timeToinform(int emp,vector<int>& manager,vector<int>& informTime,vector<int>& pTime)
    {
        if(pTime[emp]>=0) return pTime[emp];
        
        int mngr = manager[emp];
        pTime[emp] = informTime[mngr] + timeToinform(mngr,manager,informTime,pTime);
        ans=max(ans,pTime[emp]);
        return pTime[emp];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        ans=0;
        pTime.resize(n,-1);
        pTime[headID] = 0;
        
        for(int i=0;i<n;i++)
        {
            if(pTime[i]==-1)
            {
                int mngr = manager[i];
                pTime[i] = informTime[mngr] + timeToinform(mngr,manager,informTime,pTime);
            }
            ans=max(ans,pTime[i]);
        }
       
        return ans;
    }
};