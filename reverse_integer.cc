// reverse integer lintcode http://www.lintcode.com/en/problem/reverse-integer/
#include <limits>

class Solution {
public:
  /**
   * @param n the integer to be reversed
   * @return the reversed integer
   */

  int reverseInteger(int n) {
    static int ret = 0;
    static int sign = (n < 0)?-1 : 1; 
    if ( abs(n) < 10)
      return sign * (ret + abs(n)); 
    ret = (ret + (abs(n) % 10)) * 10; 
    if (ret > std::numeric_limits<int>::max() / 10) return 0;   
    return reverseInteger( (abs(n) - abs(n) % 10) / 10 );       
  }
 
};
