#!/usr/bin/python3
a = 999
b = 100
count = 0;
palList = []
for x in range(100,1000):
    for y in range(100,1000):
        if(str(x*y) == str(x*y)[::-1]):
            palList.append(x*y)
print(max(palList))
with open('alx-low_level_programming/0x17-doubly_linked_lists/102-result', 'w') as file:
    file.write(str(largest_palindrome))
