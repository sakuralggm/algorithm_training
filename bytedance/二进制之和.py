def solution(binary1, binary2):
    #  Convert binary to decimal
    decimal1 = int(binary1, 2)
    decimal2 = int(binary2, 2)
    #  Add the two decimal numbers and convert the result to binary
    ans = decimal1 + decimal2
    return str(ans)
if __name__ == "__main__":
    #  You can add more test cases here
    print(solution("101", "110") == "11")
    print(solution("111111", "10100") == "83")
    print(solution("111010101001001011", "100010101001") == "242420")
    print(solution("111010101001011", "10010101001") == "31220")