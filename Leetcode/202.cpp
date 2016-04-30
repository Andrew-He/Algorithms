/*
	Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
*/
class Solution {
public:
stack<int> getDigits(int number){
         stack<int> digits; 
        while (number != 0){
            int remid = number % 10; 
            digits.push(remid); 
            number = (number - remid) /10; 
        }
        return digits; 
}


    bool isHappy(int n) {
        int sum = n; 
        int cnt = 1; 
        while (true){
            int temp = 0; 
            stack<int> digits = getDigits(sum); 
            cnt++; 
            while (!digits.empty())
            {
                int n = digits.top(); 
                temp += n * n; 
                digits.pop(); 
            } 
            if (temp == 1) break; 
            else {
                sum = temp; 
            }
            if (cnt > 42) return false;    // hardcoded the hault condition, I do not know how to mathmatically prove, but a magic number 
        }
        return true; 
    }
};