def solution(a, b):
    # 求a和b的交集
    a = set(a)
    b = set(b)
    res = list(a & b)
    res.sort(reverse=True)
    return res

if __name__ == '__main__':
    print(solution([1, 2, 3, 7], [2, 5, 7]) == [7, 2])
    print(solution([1, 4, 8, 10], [2, 4, 8, 10]) == [10, 8, 4])
    print(solution([3, 5, 9], [1, 4, 6]) == [])
    print(solution([1, 2, 3], [1, 2, 3]) == [3, 2, 1])