import bisect

def solution(A):
    A.sort()
    ans = 0
    for i in range(len(A)):
        # 找到第一个大于A[i]的数的下标，用二分的库函数，类似于C++中的lower_bound
        index = bisect.bisect_left(A, A[i] + 1)
        if index - 1 >= len(A) - index:
            ans += 1
    return ans


if __name__ == "__main__":
    # Add your test cases here
    print(solution([100, 100, 100]) == 3)
    print(solution([2, 1, 3]) == 2)
    print(solution([30, 1, 30, 30]) == 3)
    print(solution([19, 27, 73, 55, 88]) == 3)
    print(solution([19, 27, 73, 55, 88, 88, 2, 17, 22]) == 5)
