class Solution 
{
    public List<List<Integer>> threeSum(int[] num) 
    {
        Arrays.sort(num);
        List<List<Integer>> res = new LinkedList<>(); 

        for (int i = 0; i < num.length-2; i++) 
        {

                int lo = i+1, hi = num.length-1, sum = 0 - num[i];
                while (lo < hi) 
                {
                    if (num[lo] + num[hi] == sum) 
                    {
                        res.add(Arrays.asList(num[i], num[lo], num[hi]));
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
               }
            while(i+1<num.length-2 && num[i]==num[i+1]) i++;
        }
        return res;
    }
}