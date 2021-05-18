DEP_LIST := FloatRegister.o Hardware.o Instruction.o Memory.o Program.o Register.o Utils.o 


all: $(DEP_LIST) test.o
	g++ -o app $(DEP_LIST) test.o

%.o: %.cpp
	g++ -c -o $@ $<

clean:
	rm -f *.o app

# FloatRegister.o
# Hardware.o
# Instruction.o
# Memory.o
# Program.o
# Register.o

