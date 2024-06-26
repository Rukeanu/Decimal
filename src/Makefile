DATE = $(shell date -R)
CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
NAME_TEST = s21_test

SRCS_TESTS = unit_tests.c \
	suite_add.c \
	suite_sub.c \
	suite_mul.c \
	suite_div.c \
	suite_from_decimal_to_float.c \
	suite_from_decimal_to_int.c \
	suite_from_float_to_decimal.c \
	suite_from_int_to_decimal.c \
	suite_negate.c \
	suite_truncate.c \
	suite_is_equal.c \
    suite_is_not_equal.c \
	suite_is_less.c \
	suite_is_greater.c \
	suite_is_greater_or_equal.c \
	suite_is_less_or_equal.c \
	suite_floor.c \
	suite_round.c

DIR_TESTS = tests
PATH_TESTS = $(addprefix $(DIR_TESTS)/, $(SRCS_TESTS))

OS := $(shell uname)
MAC_X86 := $(shell uname -a | grep -o _X86_64)
MAC_M1 := $(shell uname -a | grep -o _ARM64)

ifeq ($(OS), Linux)
	TEST_LIBS = -lcheck -pthread -lrt -lm -lsubunit
	MATH = -lm
	OPEN = xdg-open
endif

ifeq ($(MAC_M1), _ARM64)
	TEST_LIBS := -I/opt/homebrew/opt/check/include -L/opt/homebrew/opt/check/lib -lcheck
	OPEN = open
endif
ifeq ($(MAC_X86), _X86_64)
	TEST_LIBS = $(shell pkg-config --libs --cflags check) -lm
	OPEN = open
endif

all: s21_decimal.a

s21_decimal.a:
	$(CC) $(FLAGS) -c *.c
	ar rcs s21_decimal.a *.o
	ranlib s21_decimal.a

test: s21_decimal.a
	gcc --coverage -g *.c $(PATH_TESTS) -I $(DIR_TESTS) $(TEST_LIBS) -o s21_test
	./s21_test

gcov_report: test
	lcov -t "gcovreport" -o gcovreport.info -c --directory .
	genhtml -o report gcovreport.info
	open report/index.html

clang:
	clang-format -n *.c *.h

leaks: clean test
	leaks -atExit -- ./s21_test

valgrind: clean test
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes ./s21_test

rebuild: clean build

clean:
	rm -rf $(NAME_TEST) *.o *.a *.gcno *.gcda *.gcov *.info report a.out *.dSYM obj
	rm -rf .clang-format
	