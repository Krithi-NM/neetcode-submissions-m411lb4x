class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int m = B.size();

    if (n > m) return findMedianSortedArrays(B, A);

    int low = 0, high = n;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n + m + 1) / 2 - cut1;

        int leftA  = (cut1 == 0) ? INT_MIN : A[cut1 - 1];
        int rightA = (cut1 == n) ? INT_MAX : A[cut1];

        int leftB  = (cut2 == 0) ? INT_MIN : B[cut2 - 1];
        int rightB = (cut2 == m) ? INT_MAX : B[cut2];

        if (leftA <= rightB && leftB <= rightA) {
            if ((n + m) % 2 == 1)
                return max(leftA, leftB);
            else
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
        } 
        else if (leftA > rightB) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1;
        }
    }

    return 0.0; 
    }
};
