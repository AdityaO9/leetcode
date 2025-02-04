#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int searchIdx1 = (m + n) / 2, searchIdx2 = searchIdx1 - 1;
        int i = 0, j = 0, count = 0;
        int elem1 = -1, elem2 = -1;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                if (count == searchIdx1) elem1 = nums1[i];
                if (count == searchIdx2) elem2 = nums1[i];
                count++;
                i++;
            } else {
                if (count == searchIdx1) elem1 = nums2[j];
                if (count == searchIdx2) elem2 = nums2[j];
                count++;
                j++;
            }
        }
        while (i < m) {
            if (count == searchIdx1) elem1 = nums1[i];
            if (count == searchIdx2) elem2 = nums1[i];
            count++;
            i++;
        }
        while (j < n) {
            if (count == searchIdx1) elem1 = nums2[j];
            if (count == searchIdx2) elem2 = nums2[j];
            count++;
            j++;
        }
        if ((m + n) % 2 != 0) {
            return elem1;
        } else {
            return (elem1 + elem2) / 2.0;
        }
    }
};