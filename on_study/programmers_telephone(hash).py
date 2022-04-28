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