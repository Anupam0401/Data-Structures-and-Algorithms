def check_anagram(word1,word2):
    if len(word1) != len(word2):
        return False
    # create a hash_map for word1
    hash_map = {}
    for i in word1:
        if i in hash_map:
            hash_map[i] += 1
        else:
            hash_map[i] = 1
    # check if word2 is anagram of word1
    for i in word2:
        if i in hash_map:
            hash_map[i] -= 1
        else:
            return False
    for i in hash_map:
        if hash_map[i] != 0:
            return False
    return True

if __name__ == "__main__":
    word1 = "listen"
    word2 = "silent"
    print(check_anagram(word1,word2))