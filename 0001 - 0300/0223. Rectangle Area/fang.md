### :school:小学数学题

:warning:输入样例为：`0,0,50000,40000,0,0,50000,40000`时

如果`return M + N - O`，必定溢出
但是`return M - O + N`，不会


```c++
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int M = (C-A)*(D-B);
        int N = (G-E)*(H-F);
        int O = A>G || B>H || C<E || D<F ? 0 : (min(C, G)-max(A, E))*(min(D, H)-max(B, F));
        return M - O + N;
    }
};
```