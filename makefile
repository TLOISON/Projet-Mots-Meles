Programme: Start.o Outil.o 
	gcc -o Programme Start.o Outil.o -Wextra -lm

Start.o:Start.c  
	gcc -c Start.c -Wextra -lm

Outil.o:Outil.c 
	gcc -c Outil.c -Wextra -lm
