def solution(inp):
    # Edit your code here
    count = {}
    for num in inp:
        if num in count:
            count[num] += 1
        else:
            count[num] = 1

    for num, cnt in count.items():
        if cnt == 1:
            return num


if __name__ == "__main__":
    # Add your test cases here

    print(solution([1, 1, 2, 2, 3, 3, 4, 5, 5]) == 4)
    print(solution([0, 1, 0, 1, 2]) == 2)