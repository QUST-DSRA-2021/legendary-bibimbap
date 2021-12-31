#!/usr/bin/env Python
# -*- coding: utf-8 -*-

def anagramSolution4(str1: str, str2: str) -> bool:
    word_nums1 = [0] * 26
    word_nums2 = [0] * 26
    for k in range(len(str1)):
        word_nums1[ord(str1[k]) - ord("a")] += 1
    for ch in str2:
        word_nums2[ord(ch) - ord("a")] += 1
    for k in range(26):
        print(k)
        if word_nums1[k] != word_nums2[k]:
            return False
    return True

if __name__ == "__main__":
    print(anagramSolution4("miku", "miuk"))
