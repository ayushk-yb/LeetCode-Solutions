class Solution {
public:
    double solve(double x, long long n)
    {
        if(n == 0)
            return 1;
        
        if(n % 2 == 0)
        {
            return solve(x * x, n / 2);
        }
        else
        {
            return x * solve(x, n - 1);
        }
    }
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0)
            return 1 / solve(x, -N);
        
        return solve(x, N);
    }
};