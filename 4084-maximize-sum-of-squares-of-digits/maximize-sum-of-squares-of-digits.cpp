
#include <string>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)
            return "";

        int nines = sum / 9;
        int remainder = sum % 9;

        string result(num, '0');

        for (int i = 0; i < nines; i++) {
            result[i] = '9';
        }

        if (remainder > 0) {
            result[nines] = '0' + remainder;
        }

        return result;
    }
};
