build:
	rm -f ./a.out
	g++ -std=c++20 -g -Wall -pedantic -Werror main.cpp nupython.o -lm -Wno-psabi -Wno-unused-variable -Wno-unused-function 

run:
	./a.out

valgrind:
	rm -f ./a.out
	g++ -std=c++20 -g -Wall -pedantic -Werror main.cpp nupython.o -lm -Wno-psabi -Wno-unused-variable -Wno-unused-function 
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./a.out

valgrindf:
	rm -f ./a.out
	g++ -std=c++20 -g -Wall -pedantic -Werror main.cpp nupython.o -lm -Wno-psabi -Wno-unused-variable -Wno-unused-function 
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./a.out "$(file)"

clean:
	rm -f ./a.out
  
submit:
	/gradescope/gs submit 1396807 8995158 main.cpp

commit:
	git add .
	git commit -m "$(msg)"

push:
	git push origin main

