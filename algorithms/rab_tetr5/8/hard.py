def count_ways(n, memo = {}):
    if n in memo:
        return memo[n]
    elif n == 0 or n == 1:
        return 1
    elif n == 2:
        return 2
    else:
        result = count_ways(n - 1, memo) + count_ways(n - 2, memo) + count_ways(n - 3, memo)
        memo[n] = result
        return result
    
n = float(input('N: '))
print(count_ways(n))
