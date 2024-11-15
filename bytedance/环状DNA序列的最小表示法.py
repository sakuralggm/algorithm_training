def solution(dna_sequence):
    chset = list(dna_sequence)
    chset.sort()
    min_ch = chset[0]
    ans = []
    for i in range(len(dna_sequence)):
        if dna_sequence[i] == min_ch:
            ans.append(dna_sequence[i:] + dna_sequence[:i])
    ans.sort()
    return ans[0]
        

if __name__ == "__main__":
    #  You can add more test cases here
    print(solution("ATCA") == "AATC")
    print(solution("CGAGTC") == "AGTCCG")
    print(solution("TCATGGAGTGCTCCTGGAGGCTGAGTCCATCTCCAGTAG") == "AGGCTGAGTCCATCTCCAGTAGTCATGGAGTGCTCCTGG")