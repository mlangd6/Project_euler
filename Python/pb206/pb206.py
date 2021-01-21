#!/usr/bin/env python3

# On fait le constat que le nombre fini par 0, donc sa racine aussi.
# On constate aussi que 10^9 < x < 10^10
# On peut donc chercher naïvement le résultat sur les 1 milliards de nombre finisant par 0 dans cet intervalle. On peut majorer plus précisément x. En effet x² est entre 1020304050607080900 et 1929394959697989900. 10^9 < x < 2*10^9
# On constate que 1.01*10^9 < x < 1.4*10^9
# On constate que x doit finir par 30 ou 70 pour que x^2 finisse par 900.


import time

def is_concealed(x):
	s = "1_2_3_4_5_6_7_8_9_0"
	b = True
	for i in range(0, len(s), 2):
		if s[i] != x[i]:
			b = False
	return b

def concealed_square():
	
	'''for i in range(1010000030, 1400000000, 20):
		b = True
		if i%100 != 30 and i%100 != 70:
			b = False
		else :
			for j in range(0, len(s), 2):
				x = str(i*i)
				if s[j] != x[j]:
					b = False
		if b: 
			return i
	return -1'''

	b = False
	x = 1010000030
	while not b:
		b = is_concealed(str(x*x))
		if not b:
			if x%100 == 30:
				x += 40
			else:
				x += 60
	return x			

def main():
	start = time.time()
	x = concealed_square()
	end = time.time()

	print("The unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0 where each _ is a single digit is", x, "in", end-start, "seconds")

if __name__ == "__main__" : main()
