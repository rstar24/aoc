from itertools import starmap


data = open("/home/rishabh/mycode/aoc/2015/Day2/p3-input.txt").read().splitlines()
dimensions = [sorted(map(int, line.split('x'))) for line in data]

paper =  lambda a, b, c: 3*a*b + 2*b*c + 2*c*a
ribbon = lambda a, b, c: 2*a + 2*b + a*b*c

print(sum(starmap(paper, dimensions)))
print(sum(starmap(ribbon, dimensions)))