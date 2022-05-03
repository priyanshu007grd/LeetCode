# C++
```
class Solution {
public:
int findUnsortedSubarray(vector<int>& nums)
{
int n=nums.size();
​
int l=-1,r=-2;
int minV=nums[n-1],maxV=nums[0];
​
for(int i=0;i<n;i++)
{
maxV=max(maxV,nums[i]);
if(nums[i]<maxV) r=i;
}
​
for(int i=n-1;i>=0;i--)
{
minV=min(minV,nums[i]);
if(nums[i]>minV) l=i;
}
​
return r-l+1;
}
};
/*
class Solution {
public:
int findUnsortedSubarray(vector<int>& nums)
{
int n=nums.size();
int left=0,right=n-1;
while(left<n-1 && nums[left]<=nums[left+1]) left++;
while(right>0 && nums[right-1]<=nums[right]) right--;
if(left < right)
{
int minV=INT_MAX,maxV=INT_MIN;
for(int i=left;i<=right;i++)
{
minV=min(minV,nums[i]);
maxV=max(maxV,nums[i]);
}
while(left>=0 && nums[left]>minV) left--;
while(right<n && nums[right]<maxV) right++;
}
if(left>=right) return 0;
return right-left-1;
}
};
*/
```