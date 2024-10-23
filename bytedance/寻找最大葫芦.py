from collections import Counter

def solution(n, max, array):
    count = Counter(array)
    order = {1: 1, 13: 2, 12: 3, 11: 4, 10: 5, 9: 6, 8: 7, 7: 8, 6: 9, 5: 10, 4: 11, 3: 12, 2: 13}
    a = sorted(set(array), key=lambda x: order[x])
    first = 0
    for i in a:
        if count[i] >= 3:
            count[i] -= 3
            first = i
            for j in a:
                if count[j] >= 2:
                    if first * 3 + j * 2 <= max:
                        return [first, j]
            count[i] += 3
    return [0, 0]
                
if __name__ == "__main__":
    # Add your test cases here
    print(solution(9, 34, [6, 6, 6, 8, 8, 8, 5, 5, 1]) == [8, 5])
    print(solution(9, 37, [9, 9, 9, 9, 6, 6, 6, 6, 13]) == [6, 9])
    print(solution(9, 40, [1, 11, 13, 12, 7, 8, 11, 5, 6]) == [0, 0])
