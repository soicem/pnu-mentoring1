/*
return type: boolean
Input string

1 <= s.size() <= 2 * 10^5 : N

N^2 -> 10^10
10^9

linear search(N), binary search(log N)

TC1 - general case (true)
Input: s = "ABCBA"
Output: true

TC2 - general case (false)
Input: s = "ABCDE"
Output: false

TC3 - single entity
Input: s = "s"
Output: true

arr: [1,2,3,4,5,6]

(설계)
Approach 1.
- two pointers(left++, right--)
- Time Complexity: O(N), N: a size of s
- Space Complexity: O(1)
*/

bool isValidPalindrome(string& s) {
    int left = 0, right = s.size() - 1;
    
    /*
    Input: s = "A BCD E"
    left = 0, right = 4
    */
    
    while(left <= right) {
        char c = s[left];
        if('A' <= c && c <= 'Z') {
            c = 'a' + (c - 'A');
        }
        
        if(s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
