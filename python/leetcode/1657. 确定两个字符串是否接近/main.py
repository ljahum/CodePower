from collections import Counter
def func( word1, word2):
    # if(len(word1)!=len(word2)):
    #     return False
    # if(set(word1)!=set(word2)):
    #     return False
    # # print(Counter(word1).values())
    # return Counter(Counter(word1).values()) == Counter(Counter(word2).values())
    return len(word1)==len(word2) and\
            set(word1)==set(word2) and\
            Counter(Counter(word1).values()) == Counter(Counter(word2).values())
    
    
    
    
word1 = "aabbcc"
word2 = "aaccbb"
func(word1,word2)