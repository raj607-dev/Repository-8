class Solution {
 public:
  int guessMajority(ArrayReader& reader) {
    const int n = reader.length();
    const int query0123 = reader.query(0, 1, 2, 3);
    const int query1234 = reader.query(1, 2, 3, 4);
    // the number of numbers that are same as `nums[0]`
    int zeros = 1;
    // the number of numbers that are different from `nums[0]`
    int nonZeros = 0;
    // any index i s.t. nums[i] != nums[0]
    int indexNot0 = -1;

    // Find which group nums[1..3] belong to.
    for (int i = 1; i <= 3; ++i) {
      vector<int> abcd = getABCD(i);
      if (reader.query(abcd[0], abcd[1], abcd[2], abcd[3]) == query1234) {
        ++zeros;
      } else {
        ++nonZeros;
        indexNot0 = i;
      }
    }

    // Find which group nums[4..n) belong to.
    for (int i = 4; i < n; ++i)
      if (reader.query(1, 2, 3, i) == query0123) {
        ++zeros;
      } else {
        ++nonZeros;
        indexNot0 = i;
      }

    if (zeros == nonZeros)
      return -1;
    if (zeros > nonZeros)
      return 0;
    return indexNot0;
  }

 private:
  // Returns [0..4] except i.
  vector<int> getABCD(int i) {
    vector<int> abcd{0};
    for (int j = 1; j <= 3; ++j)
      if (j != i)
        abcd.push_back(j);
    abcd.push_back(4);
    return abcd;
  }
};
