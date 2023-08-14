class Solution 
{
    int[] nums1;
    int[] nums2;
    int n1,n2;

    int getKth(int s1,int s2,int k)
    {
        if(s1>=n1) return nums2[s2+k-1];
        if(s2>=n2) return nums1[s1+k-1];
        if(k==1) return Math.min(nums1[s1],nums2[s2]);
        System.out.println(s1);
        System.out.println(s2);
         System.out.println(k);
        System.out.println();



        int m1=s1+k/2-1<n1?nums1[s1+k/2-1]:Integer.MAX_VALUE;
        int m2=s2+k/2-1<n2?nums2[s2+k/2-1]:Integer.MAX_VALUE;
        if(m1<m2) return getKth(s1+k/2,s2,k-k/2);
        return getKth(s1,s2+k/2,k-k/2);
    }
    public double findMedianSortedArrays(int[] nums1, int[] nums2) 
    {
        this.nums1=nums1;
        this.nums2=nums2;
        this.n1=nums1.length;
        this.n2=nums2.length;

        int l=(n1+n2+1)/2;
        int r=(n1+n2+2)/2;

        return ( Double.valueOf(getKth(0,0,l)) + Double.valueOf(getKth(0,0,r)) )/2.0;
    }
}