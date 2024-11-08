def solution(version1, version2):
    ver1 = version1.split('.')
    ver2 = version2.split('.')
    length = max(len(ver1), len(ver2))
    while (length > len(ver1)):
        ver1.append('0')
    while (length > len(ver2)):
        ver2.append('0')
    for i in range(length):
        if int(ver1[i]) > int(ver2[i]):
            return 1
        elif int(ver1[i]) < int(ver2[i]):
            return -1
    return 0


if __name__ == "__main__":
    # Add your test cases here

    print(solution("0.1", "1.1") == -1)
    print(solution("1.0.1", "1") == 1)
    print(solution("7.5.2.4", "7.5.3") == -1)
    print(solution("1.0", "1.0.0") == 0)
