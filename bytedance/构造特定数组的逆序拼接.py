def solution(n: int) -> list:
    ans = [j for i in range(n) for j in range(n, i, -1)]
    return ans
    
if __name__ == '__main__':
    print(solution(3) == [3, 2, 1, 3, 2, 3])
    print(solution(4) == [4, 3, 2, 1, 4, 3, 2, 4, 3, 4])
    print(solution(5) == [5, 4, 3, 2, 1, 5, 4, 3, 2, 5, 4, 3, 5, 4, 5])