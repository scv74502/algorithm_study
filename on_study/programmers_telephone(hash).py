"""
전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.
"""

def solution(phone_book):
    hasp_map = {}
    for pNumber in phone_book:
        hasp_map[pNumber] = 1

    for phone_num in phone_book:
        temp = ''
        for num in phone_num:
            temp += num
            if temp in hasp_map and temp != phone_num:
                return False
    return True


# test cases
test1 = ["119", "97674223", "1195524421"]   #false
test2 = ["123","456","789"] #true
test3 = ["12","123","1235","567","88"]  #false

# test
print(solution(test1))  #false
print(solution(test2))  #true
print(solution(test3))  #false