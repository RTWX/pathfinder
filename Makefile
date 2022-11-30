CLANG = clang -std=c11 -Wall -Wextra -Werror -Wpedantic
SF = src/*.c 
OD = obj
EFN = pathfinder

all: install clean

install: 
	@make install -sC libmx
	@${CLANG} -L./libmx -o ${EFN} ${SF} -lmx

uninstall: clean
	@make uninstall -sC libmx
	@rm -f ${EFN}

clean:
	@make clean -sC libmx
	@rm -rdf ${OD} 

reinstall: uninstall install clean 


