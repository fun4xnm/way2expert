#ifndef RESHAPE_MATRIX_H_
#define RESHAPE_MATRIX_H_

#include <algorithm>
#include <vector>

namespace problem {

// Assume you are an awesome parent and want to give your children some cookies.
// But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie
// that the child will be content with; and each cookie j has a size s[j]. If
// s[j] >= g[i], we can assign the cookie j to the child i, and the child i will
// be content. Your goal is to maximize the number of your content children and
// output the maximum number.
// 1 <= g.length <= 3 * 104
// 0 <= s.length <= 3 * 104
// 1 <= g[i], s[j] <= 231 - 1
int FindContentChildren(std::vector<int>& g, std::vector<int>& s) {
  std::sort(g.begin(), g.end());
  std::sort(s.begin(), s.end());
  int given = 0;
  for (auto i = 0; i < s.size(); i++) {
    if (given < g.size() && s[i] >= g[given]) {
      given++;
    }
  }
  return given;
}

}  // namespace problem

#endif