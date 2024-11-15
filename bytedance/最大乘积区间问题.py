def solution(n, data):
    max_product = -1
    max_x = 1
    max_y = 1
    current_product = 1
    current_start = 0
    for i in range(n):
        if data[i] == 0:
            if max_product < 0 or 0 > max_product:
                max_product = 0
                max_x = i + 1
                max_y = i + 1
            current_product = 1
            current_start = i + 1
        else:
            current_product *= data[i]
            if current_product > max_product:
                max_product = current_product
                max_x = current_start + 1
                max_y = i + 1
            elif current_product == max_product:
                if (current_start + 1) < max_x:
                    max_x = current_start + 1
                    max_y = i + 1
                elif (current_start + 1) == max_x and (i + 1) < max_y:
                    max_y = i + 1
    return [max_x, max_y]


if __name__ == "__main__":
    # Add your test cases here
    print(solution(5, [1, 2, 4, 0, 8]) == [1, 3])
    print(solution(7, [1, 2, 4, 8, 0, 256, 0]) == [6, 6])
