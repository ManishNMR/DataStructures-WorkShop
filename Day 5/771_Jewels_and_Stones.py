# https://leetcode.com/problems/jewels-and-stones/
# 771. Jewels and Stones

# Input: jewels = "aA", stones = "aAAbbbb"
# Output: 3

def numJewelsInStones(jewels, stones):
        """
        :type jewels: str
        :type stones: str
        :rtype: int
        """
        count=0
        for i in stones:
            if i in jewels:
                count=count+1
        return count

if __name__=="__main__": 
     a = input()
     b = input()
     print(f"Jewels In Stone: {numJewelsInStones(a,b)}")

'''
3110. Score of a String
@author: nmanish_0128
'''