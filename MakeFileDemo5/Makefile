CC = gcc 

#defualt target 
#     dependacies
app: main.o helper.o 
	$(CC) main.o helper.o -o app

main.o: 
	$(CC) -c main.c 

helper.o:
	$(CC) -c helper.c 

# delete the file
clean: 
	rm -f app *.o

run: 
	./app