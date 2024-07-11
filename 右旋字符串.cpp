#include "include/leetcode_structures.h"
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    void reverse(string& s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }

public:
    string rotateString(string s, int k) {
        reverse(s, 0, s.size() - 1);
        if (k >= s.size()) {
            return s;
        }
        reverse(s, 0, k - 1);
        reverse(s, k, s.size() - 1);
        return s;
    }
};