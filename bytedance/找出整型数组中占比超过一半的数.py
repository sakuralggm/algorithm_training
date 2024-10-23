def solution(array):
    cnt = 0
    cur = -2e9
    for i in range(0, len(array)):
        if cur == -2e9:
            cur = array[i]
            cnt = 1
        elif array[i] == cur:
            cnt += 1
        else:
            cnt -= 1
            if cnt == 0:
                cur = -2e9
                cnt = 0
    return cur
                


if __name__ == "__main__":
    # Add your test cases here

    print(solution([1, 3, 8, 2, 3, 1, 3, 3, 3]) == 3)
