class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        cache = {}
        return paths(m, n, cache)


def paths(m, n, cache):
    if m == 1 or n == 1:
        return 1
    if (m, n) in cache:
        return cache[(m, n)]
    if (n, m) in cache:
        return cache[(n, m)]

    result = paths(m - 1, n, cache) + paths(m, n - 1, cache)
    cache[(m, n)] = result
    cache[(n, m)] = result

    return result

