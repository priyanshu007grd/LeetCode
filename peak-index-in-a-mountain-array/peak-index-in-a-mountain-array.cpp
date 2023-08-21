class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (arr[mid] < arr[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

/*
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        while (arr[i] < arr[i + 1]) {
            i++;
        }
        return i;
    }
};
*/
