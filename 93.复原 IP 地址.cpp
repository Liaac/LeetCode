/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
// #include "include/leetcode_structures.h"
// #include <vector>
// #include <string>
// #include <stack>
// #include <queue>
// #include <unordered_map>
// #include <unordered_set>
// using namespace std;

// @lc code=start
class Solution {
private:
    vector<string> _res;
    string _path;

    bool isValid(string& s, int start, int end) {
        if (end - start + 1 > 3) return false;
        if (s[start] == '0' && start != end) return false;
        int num = 0;
        for (int i = start; i <= end; ++i) {
            num = num * 10 + s[i] - '0';
            if (num > 255) return false;
        }
        return true;
    }

    void backtrack(string& s, int start, int count) {
        if (start == s.length()) {
            if (count == 4) {
                _res.push_back(_path);
            }
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            if (isValid(s, start, i)) {
                int len = _path.length();
                _path += s.substr(start, i - start + 1);
                if (count < 3) {
                    _path += ".";
                }
                backtrack(s, i + 1, count + 1);
                _path.erase(len);
            } else break;
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12) return _res;
        backtrack(s, 0, 0);
        return _res;
    }
};
// @lc code=end

