main: main.o	SimpleLinkList.o
	gcc main.o  SimpleLinkList.o -o main
	
main.o:	main.c SimpleLinkList.c 
	gcc -c main.c
	
SimpleLinkList.o:	SimpleLinkList.c SimpleLinkList.h
	gcc -c SimpleLinkList.c
	
clear:
	del	*.o