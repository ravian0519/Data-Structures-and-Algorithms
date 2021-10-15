def  climbStairs(n, dic = {0:0,1:1,2:2}):
    """
    LeetCode-Problem:
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
    Solution:
    Exploring all possible ways to climb the stairs in 1 or 2 steps. And using the dictionary to keep
    record of the paths we already explored.
    """
    if n in dic.keys():
        return dic[n]
    else:
        dic[n] =  climbStairs(n-1,dic) + climbStairs(n-2,dic)
        return dic[n]  


