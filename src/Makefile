CC=gcc
CFLAGS=-g -Wall -Werror -Wextra -std=c11 -pedantic #-fsanitize=address
GCOVFLAGS:=-fprofile-arcs -ftest-coverage # -fsanitize=address
LDFLAGS:=-lcheck -lgcov

ifeq ($(shell uname), Linux)
LDFLAGS +=-pthread -lcheck   -lrt -lm #-lsubunit
endif

SOURCES:= s21_matrix.c

OBJECTS = $(addprefix objects/,$(SOURCES:.c=.o))
OBJECTS_GCOV = $(addprefix gcov_obj/,$(SOURCES:.c=.o))

.PHONY: all clean rebuild lint

all: clean s21_matrix.a 

build: test gcov_report ss21_matrix_gcov.a 

s21_matrix_gcov.a: $(OBJECTS_GCOV)
	ar -src $@ $(OBJECTS_GCOV)

s21_matrix.a: $(OBJECTS)
	ar -src $@ $(OBJECTS)

test: rebuild gcov_obj/s21_matrix_test.o s21_matrix_gcov.a
	$(CC) gcov_obj/s21_matrix_test.o s21_matrix_gcov.a -o $@ $(LDFLAGS) $(GCOVFLAGS)
	./test

gcov_report: rebuild test
	lcov -c -d gcov_obj/. -o gcov_obj/coverage.info
	genhtml gcov_obj/coverage.info --output-directory out

gcov_obj/%.o: %.c
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

objects/%.o: %.c
	$(CC) -g -Wall -Werror -Wextra -c $< -o $@


rebuild: clean all

clean:
	rm -f */*.o
	rm -f report
	rm -f gcov_obj/*.gc*
	rm -f ./test
	rm -f -r out
	rm -f -r ./*gcno
	rm -f gcov_obj/*.info
	rm -f .DS_Store
	rm -f *.a
	rm -f ./a.out

check:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.h *.c ./gcov_obj/*.c
	rm -f CPPLINT.cfg
