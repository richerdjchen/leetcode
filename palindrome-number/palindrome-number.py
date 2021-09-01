class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (x < 0):
            return False
        l = []
        while(x > 0):
            n = x % 10
            x = x//10
            l.append(n)
        if (len(l) == 0):
            return True
        r = len(l) // 2
        for i in range(r):
            if (l[i] != l[len(l)-i-1]):
                return False
        return True