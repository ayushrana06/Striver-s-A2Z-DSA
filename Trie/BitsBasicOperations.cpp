# include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int XOR(int n, int m) {
        // code here
        return n^m;
    }
    int check(int a, int b) {
        // code here
        return (bool)(b&(1<<a-1));
    }
    int setBit(int c, int d) {
        // code here
        return d|(1<<c);
    }
};