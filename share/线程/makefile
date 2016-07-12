CCFLAGS=-D_REENTRANT
pthread1: pthread1.c
	gcc -o pthread1 pthread1.c $(CCFLAGS) -I/usr/include/nptl -L/usr/lib/nptl -lpthread
pthread2: pthread2.c
	gcc -o pthread2 pthread2.c $(CCFLAGS) -I/usr/include/nptl -L/usr/lib/nptl -lpthread
clean:
	rm pthread1
	rm pthread2
