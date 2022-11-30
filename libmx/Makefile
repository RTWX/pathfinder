CLANG = clang -std=c11 -Wall -Wextra -Werror -Wpedantic
SF = src/*.c 
OD = obj
EFN = libmx.a

all: install clean

install:
	@${CLANG} -c ${SF}
	@mkdir ${OD}
	@mv *.o ${OD}
	@ar -rc ${EFN} ${OD}/*.o

uninstall: clean
	@rm -f ${EFN}

clean:
	@rm -rdf ${OD} 

reinstall: uninstall install  clean 


