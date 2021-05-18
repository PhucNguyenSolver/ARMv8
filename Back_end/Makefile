DEP_LIST := FloatRegister.h   Hardware.h   Instruction.h   Memory.h   Program.h   Register.h   Utils.h 
DEP_LIST := FloatRegister.cpp Hardware.cpp Instruction.cpp Memory.cpp Program.cpp Register.cpp Utils.cpp


all:	
	g++ -o app $(DEP_LIST)

%.o: %.cpp %.h
	g++ -c -o $@ $<

clean:
	rm -f *.o app

# FloatRegister.o
# Hardware.o
# Instruction.o
# Memory.o
# Program.o
# Register.o

