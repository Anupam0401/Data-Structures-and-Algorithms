public String longestPalindrome(String s) {
  if (s == null || s.length() < 1) return "";
  int start = 0, end = 0;
  for (int i = 0; i < s.length(); i++) {
      int len1 = expandAroundCenter(s, i, i);
      int len2 = expandAroundCenter(s, i, i + 1);
      int len = Math.max(len1, len2);
      if (len > end - start) {
          start = i - (len - 1) / 2;
          end = i + len / 2;
      }
  }
  return s.substring(start, end + 1);
}

private int expandAroundCenter(String s, int left, int right) {
  int L = left, R = right;
  while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
      L--;
      R++;
  }
  return R - L - 1;
}

void manachers(String s){
  int n = s.length();
  String t = preProcess(s);
  int[] p = new int[t.length()];
  int C = 0, R = 0;
  for (int i = 1; i < t.length() - 1; i++) {
      int i_mirror = 2 * C - i; // equals to i' = C - (i-C)

      if (R > i) {
          p[i] = Math.min(R - i, p[i_mirror]);
      }

      // Attempt to expand palindrome centered at i
      while (t.charAt(i + 1 + p[i]) == t.charAt(i - 1 - p[i])) {
          p[i]++;
      }

      // If palindrome centered at i expand past R,
      // adjust center based on expanded palindrome.
      if (i + p[i] > R) {
          C = i;
          R = i + p[i];
      }
  }

  // Find the maximum element in p.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < t.length() - 1; i++) {
      if (p[i] > maxLen) {
          maxLen = p[i];
          centerIndex = i;
      }
  }

  // Find the starting index of palindrome in s.
  int start = (centerIndex - 1 - maxLen) / 2;

  // Print palindrome centered at start.
  System.out.println(s.substring(start, start + maxLen));
}