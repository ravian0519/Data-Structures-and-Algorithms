def fib(n,dic= {0:0,1:1}):
    """
    Fibonacci with Memoization
    """
    if n in dic.keys():
        return dic[n]

    else:
        dic[n] = fib(n-1) + fib(n-2)
        return dic[n]


