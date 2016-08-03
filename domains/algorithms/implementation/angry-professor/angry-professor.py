#!/bin/python3
#
# angry-professor.py
# https://www.hackerrank.com/challenges/angry-professor
#
# Solution by mabernardo
# https://github.com/mabernardo
# https://www.hackerrank.com/mabernardo
#
def cancelled(arrivals, threshold):
    ontime = 0
    for a in arrivals:
        if a <= 0:
            ontime += 1
    return ontime < threshold


tests = int(input().strip())
for i in range(tests):
    students, threshold = input().strip().split(' ')
    students, threshold = [int(students), int(threshold)]
    a = [int(a_temp) for a_temp in input().strip().split(' ')]

    if cancelled(a, threshold):
        print("YES")
    else:
        print("NO")
