class Solution:
    def addBinary(self, a: str, b: str) -> str:
        max_len = max(len(a), len(b))
        a = a.zfill(max_len)
        b = b.zfill(max_len)

        carry_over = 0
        result_sum = []

        for i in range(0, max_len):
            if a[max_len - 1 - i] == '1':
                carry_over += 1
            if b[max_len - 1 - i] == '1':
                carry_over += 1

            if carry_over % 2 == 1:
                result_sum.append('1')
            else:
                result_sum.append('0')

            carry_over //= 2

        if carry_over:
            result_sum.append('1')
        result_sum.reverse()

        return "".join(result_sum)

