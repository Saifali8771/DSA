#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char* s) {
    int len = strlen(s);
    int left = 0, right = 0, maxLength = 0;

   
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxLength = MAX(maxLength, 2 * right);
        } else if (right > left) {
            left = right = 0;
        }
    }

    left = right = 0;

    for (int i = len - 1; i >= 0; --i) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        if (left == right) {
            maxLength = MAX(maxLength, 2 * left);
        } else if (left > right) {
            left = right = 0;
        }
    }
    return maxLength;
}