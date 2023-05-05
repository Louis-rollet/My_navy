##
## EPITECH PROJECT, 2023
## B-PSU-100-MPL-1-1-navy-aurelien.baraquin
## File description:
## Makefile
##

CC = gcc
SRC = 	src/lib.c \
		src/load_file_in_str.c \
		src/main.c \
		src/player_one.c \
		src/player_two.c \
		src/main_game.c \
		src/create_map.c \
		src/send_number.c \
		src/init_struct.c \
		src/display.c \
		src/reset_and_collide.c \
		src/verif_coo.c \
		src/win_function.c \
		src/verif_map.c \
		src/verif_hit_three.c\

GLOB = src/global.c
TARGET = navy
OBJ = $(GLOB:.c=.o)

$(TARGET) : $(OBJ)
	make re -C my_printf/
	$(CC) -o $(TARGET) $(SRC) $(OBJ) -Imy_printf/ -Lmy_printf/ -lmy

all :	$(TARGET)

clean :
	rm -rf $(OBJ)
	rm -rf ./my_printf/*.o

fclean : clean
	rm -rf $(TARGET)
	rm -rf ./my_printf/libmy.a

re : fclean all
