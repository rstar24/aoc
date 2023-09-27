p1-p2:
	cd ~/mycode/aoc/output/  && gcc ~/mycode/aoc/2015/Day1/p1-p2.c -o p1-p2 && ./p1-p2 
p3:
	cd ~/mycode/aoc/output/  && gcc ~/mycode/aoc/2015/Day2/p3.c -o p3 && ./p3 
	# This is a comment in makefile rule 
p4:
	cd ~/mycode/aoc/output/  && g++ ~/mycode/aoc/2015/Day3/p4.cpp -o p4 && ./p4 
p5:
	cd ~/mycode/aoc/output/  && g++ ~/mycode/aoc/2015/Day3/p5.cpp -o p5 && ./p5 
p6:
	cd ~/mycode/aoc/output/  && g++ ~/mycode/aoc/2015/Day4/p6.cpp ~/mycode/aoc/2015/Day4/md5.cpp  -o p6 && ./p6 | lolcat

