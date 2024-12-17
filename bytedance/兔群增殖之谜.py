def solution(A):
    # Write your code here.
    if A == 1:
        return 1
    a, b = 1, 0
    for _ in range(2, A + 1):
        a, b = a + b, a
    return a + b


if __name__ == "__main__":
    # Add your test cases here
    print(solution(2) == 2)
    print(solution(5) == 8)
    print(solution(1) == 1)
    print(solution(15) == 987)
    print(solution(50) == 20365011074)
