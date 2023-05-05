##
## EPITECH PROJECT, 2022
## B-CPE-101-MPL-1-1-myprintf-kylian.labrador
## File description:
## Makefile
##

SRC = my_printf.c\
	my_putchar.c\
	my_putnbr.c\
	my_putstr.c\
	my_strlen.c\
	print_arg.c\
	veriferror.c\
	my_putnbr_base.c\
	my_putnbr_un.c\
	space_and_bug.c\
	my_putnbr_li.c\
	format_n.c\
	my_putnbr_base_li.c\
	my_putnbr_float.c\
	my_math.c\
	my_putnbr_base_hi.c\
	my_putnbr_hi.c\
	my_putnbr_hash.c\
	print_arg_f.c\
	my_p.c\
	my_putnbr_science_maj.c
OBJ = $(SRC:.c=.o)
TARGET = libmy.a
INC = -I./
LIB = -L./ -lmy
CRIT = -lcriterion --coverage
TEST = ./tests/test_my_printf.c\
	./tests/test_my_printf_easy1.c\
	./tests/test_my_printf_easy2.c\
	./tests/test_my_printf_easy3.c\
	./tests/test_my_printf_easy4.c\
	./tests/test_my_printf_easy5.c\
	./tests/test_my_printf_easy6.c\
	./tests/test_my_printf_easy7.c\
	./tests/test_my_printf_medium1.c\
	./tests/test_my_printf_medium2.c\
	./tests/test_my_printf_medium3.c\
	./tests/test_my_printf_medium4.c\
	./tests/test_my_printf_medium5.c\
	./tests/test_my_printf_medium6.c\
	./tests/test_my_printf_medium7.c\
	./tests/test_my_printf_medium8.c
CMP = gcc
DEL = unit_tests\
	unit_tests-test_my_printf.gcda\
	unit_tests-test_my_printf.gcno\
	unit_tests-test_my_printf_easy1.gcda\
	unit_tests-test_my_printf_easy1.gcno\
	unit_tests-test_my_printf_easy2.gcda\
	unit_tests-test_my_printf_easy2.gcno\
	unit_tests-test_my_printf_easy3.gcda\
	unit_tests-test_my_printf_easy3.gcno\
	unit_tests-test_my_printf_easy4.gcda\
	unit_tests-test_my_printf_easy4.gcno\
	unit_tests-test_my_printf_easy5.gcda\
	unit_tests-test_my_printf_easy5.gcno\
	unit_tests-test_my_printf_easy6.gcda\
	unit_tests-test_my_printf_easy6.gcno\
	unit_tests-test_my_printf_easy7.gcda\
	unit_tests-test_my_printf_easy7.gcno\
	unit_tests-test_my_printf_medium1.gcda\
	unit_tests-test_my_printf_medium1.gcno\
	unit_tests-test_my_printf_medium2.gcda\
	unit_tests-test_my_printf_medium2.gcno\
	unit_tests-test_my_printf_medium3.gcda\
	unit_tests-test_my_printf_medium3.gcno\
	unit_tests-test_my_printf_medium4.gcda\
	unit_tests-test_my_printf_medium4.gcno\
	unit_tests-test_my_printf_medium5.gcda\
	unit_tests-test_my_printf_medium5.gcno\
	unit_tests-test_my_printf_medium6.gcda\
	unit_tests-test_my_printf_medium6.gcno\
	unit_tests-test_my_printf_medium7.gcda\
	unit_tests-test_my_printf_medium7.gcno\
	unit_tests-test_my_printf_medium8.gcda\
	unit_tests-test_my_printf_medium8.gcno

$(TARGET) : $(OBJ)
	ar rc $(TARGET) $(OBJ)

all :	$(TARGET)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(TARGET)

re : fclean all

unit_tests : fclean
	make $(TARGET)
	$(CMP) -o unit_tests $(TEST) $(SRC) $(CRIT)

tests_run : unit_tests
	make clean
	./unit_tests
	rm $(DEL)
	gcovr -b -s --html-details -o test01
#	rm test01*
	rm *.g*
