// Let f(x) be the number of zeroes at the end of x!. (Recall that x! = 1 * 2 * 3 * ... * x, and by convention, 0! = 1.)
//
// For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has 2 zeroes at the end. Given K, find how many non-negative integers x have the property that f(x) = K.
//
//
// Example 1:
// Input: K = 0
// Output: 5
// Explanation: 0!, 1!, 2!, 3!, and 4! end with K = 0 zeroes.
//
// Example 2:
// Input: K = 5
// Output: 0
// Explanation: There is no x such that x! ends in K = 5 zeroes.
//
//
// Note:
//
//
// 	K will be an integer in the range [0, 10^9].
//
//


class Solution {
public:
    //2，5，10
    int preimageSizeFZF(int K) {
        int low = K * 4 / 5;
        int high = K;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            int tmp = f(mid);
            if (tmp == K) return 5;
            if (tmp < K) {
                low = mid;
            } else {
                high = mid;
            }            
        }

        if (f(high) == K || f(low) == K) return 5;
        return 0;
    }

    int f(int x) {
        int k = x % 5;
        while (x / 5) {
            x /= 5;
            k += x * 5 + x % 5;
        }
        return k;
    }
};
