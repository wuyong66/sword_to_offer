#这是剑指offer第9题的变式题。

原题是一只青蛙一次可以条上一级台阶，也可以跳上2级台阶，问该青蛙跳上一个n阶台阶一共多少种跳法。

结题思路：首先当只有一个台阶的时候，只有一种跳法，当有两个台阶的时候就有（1， 1）（2）两种跳法，当有n个台阶的时候，可以看做：当第一次跳一个台阶，则剩余有n-1个台阶，有f(n - 1)种跳法，当第一次跳两个台阶，则剩余有n-2个台阶，有f(n - 2)种跳法，则共有f(n) = f(n - 1) + f(n - 2)种跳法

同样的变式题还有，用2*1的小矩形横着或者竖着放去覆盖更大的矩形，比如用8个2*1的矩形去覆盖一个2*8的大矩形，问总共有多少种方法？，结题思路是一样的而已。