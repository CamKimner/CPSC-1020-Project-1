CC = g++
CPPFLAGS = -std=c++11 -Wall

run: compile
	./pa1 animals.txt
compile:
	$(CC) -o pa1 $(CPPFLAGS) dll_list.cpp mainDriver.cpp
clean:
	rm pa1