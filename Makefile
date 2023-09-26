p1-p2:
	cd ~/mycode/aoc/output/  && gcc ~/mycode/aoc/2015/Day1/p1-p2.c -o p1-p2 && ./p1-p2 
p3:
	cd ~/mycode/aoc/output/  && gcc ~/mycode/aoc/2015/Day2/p3.c -o p3 && ./p3 
	# This is a comment in makefile rule 
p4:
	cd ~/mycode/aoc/output/  && gcc ~/mycode/aoc/2015/Day3/p4.c -o p4 && ./p4 

file0.txt:
	echo "I will make file0.txt";

file1.txt: file0.txt
	echo "THe file0 has gone through some changes";
	echo "Making file1 according to those changes";

