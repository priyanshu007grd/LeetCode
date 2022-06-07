# C++
```
class Solution
{
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
for(int i=m-1, j=n-1, k=m+n-1; j>=0; )
nums1[k--] =i>=0 && nums1[i]>nums2[j]? nums1[i--]: nums2[j--];
​
}
};
```
​
# JAVA
```
class Solution {
public void merge(int[] nums1, int m, int[] nums2, int n) {
​
int i=m+n-1;
m--;
n--;
​
while(m>=0 && n>=0) {
if(nums1[m]>=nums2[n]) {
nums1[i]=nums1[m];
m--;
} else {
nums1[i]=nums2[n];
n--;
}
i--;
}
while(m>=0) {
nums1[i]=nums1[m];
m--;
i--;
}
while(n>=0) {
nums1[i]=nums2[n];
n--;
i--;
}
}
}
```