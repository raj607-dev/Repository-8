class Solution {
 public:
  int getIndex(ArrayReader& reader) {
    int l = 0;
    int r = reader.length() - 1;

    while (l < r) {
      const int m = (l + r) / 2;
      const int res = (r - l + 1) % 2 == 0 ? reader.compareSub(l, m, m + 1, r)
                                           : reader.compareSub(l, m, m, r);
      if (res == -1)
        l = m + 1;
      else  // res == 1 || res == 0
        r = m;
    }

    return l;
  }
};
