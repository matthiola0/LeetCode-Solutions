class Solution {
public:
    char findKthBit(int n, int k) {
        int inverse = 0;
        int pivot = 1;
        for (int i = 0; i < n-1; i++) pivot *= 2;

        while (pivot != 1) {
            if (pivot == k) return (inverse % 2) ? '0' : '1';
            else if (k > pivot) {
                int shift = k - pivot;

                k = pivot - shift;
                inverse += 1;
            } 
            pivot /= 2;
        }

        return (inverse % 2) ? '1' : '0';
    }
};