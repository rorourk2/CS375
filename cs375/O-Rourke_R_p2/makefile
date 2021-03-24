P=Main
Q=Read
R=Heap

CFLAGS= -g -Wall

all: $(P)

$(P): $(P).o $(Q).o $(R).o
	g++ $(CFLAGS) $(P).o $(Q).o $(R).o -o $(P)

$(P).o: $(P).cpp $(Q).h $(R).h
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(Q).o: $(Q).cpp $(Q).h
	g++ $(CFLAGS) -c $(Q).cpp -o $(Q).o
	
$(R).o: $(R).cpp $(R).h
	g++ $(CFLAGS) -c $(R).cpp -o $(R).o

run: $(P)
	./$(P)

	
clean:
	rm -rf $(P)
	rm -rf $(P).o
	rm -rf $(Q).o
	rm -rf $(R).o
