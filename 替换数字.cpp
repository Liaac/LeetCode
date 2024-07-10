#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        int count = 0;
        int oldIndex = s.size() - 1;
        for (char c : s) {
            if (isdigit(c)) {
                ++count;
            }
        }
        s.resize(s.size() + 5 * count);
        int newIndex = s.size() - 1;
        while (oldIndex >= 0) {
            if (s[oldIndex] >= '0' && s[oldIndex] <= '9') {
                s[newIndex--] = 'r';
                s[newIndex--] = 'e';
                s[newIndex--] = 'b';
                s[newIndex--] = 'm';
                s[newIndex--] = 'u';
                s[newIndex--] = 'n';
            } else {
                s[newIndex--] = s[oldIndex];
            }
            oldIndex--;
        }
    }
};