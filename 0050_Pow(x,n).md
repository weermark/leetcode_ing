```c++

class Solution {
public:
    double pow(double x, int n){
        if(n == 1)  return x;
        else if(n == 0)  return 1;
        double tmp = myPow(x, n / 2);
        return (n % 2 == 0) ? (tmp * tmp) : (tmp * tmp * x);
    }
    
    double myPow(double x, int n) {
        if(n >= 0)
            return pow(x, n);
        else if(n < 0){
            n = -n;
            double res = pow(x, n);
            res = 1 / res;
            return res;
        }
        return 0;
    }
};
```


1.00000
-2147483648

Line 14: Char 17: runtime error: negation of -2147483648 cannot be represented in type 'int'; cast to an unsigned type to negate this value to itself (solution.cpp)
