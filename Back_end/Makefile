program:	program.cpp
	g++ -o app utils.o Hardware.o Instruction.o

# %:	$*.cpp
# 	g++ -c $*.cpp -o $*.o

%.o: %.cpp %.h
	g++ -c -o $@ $<

clean:
	rm -f *.o app