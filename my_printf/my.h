/*
** EPITECH PROJECT, 2022
** B-CPE-101-MPL-1-1-myprintf-kylian.labrador
** File description:
** my
*/
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#ifndef MY_H_
    #define MY_H_

//main function : run until end of arg and call what print the arg
int my_printf(char *format, ...);

//see if error
int veriferror(int cpt, int cpt_error);

//look if space after a %
int verif_space(char *format, int i);

//if is not a existing flag, become a error and print %arg
int verif_cpt_bug(int cpt_error, int cpt, char c);

//putchar for percent
int my_putchar_perc(va_list ap);

//verify if %flag exist in struct
int print_arg(char *format, va_list ap, int i);

//verify if %arg is l, h or #
int print_argi(char *format, va_list ap, int i);

//verify second flag after long
int print_arg2(char *format, va_list ap, int i);

//verify second flag after short
int print_arg3(char *format, va_list ap, int i);

//verify second flag after #
int print_arg4(char *format, va_list ap, int i);

//basic char display on console
int my_putchar(char);

//multiple char display on console
int my_putstr(char *str);

//lenght of a string
int my_strlen(char *str);

//%n fonction that copy int in an adress
int cpt_to_adress(va_list, int);

//put normal numbers
int my_putnbr(int);

//put number in different with void*
int my_putnbr_base_void(void *, char *);

//put long number with long int
int my_putnbr_li(long int nb);

//put float type number
int my_putnbr_float(double nb);

//put negative number with science style
int my_putnbr_science_pos(double nb);

//put positive numbers with science style
int my_putnbr_science_neg(double nb);

//put number wih diffent base like binary and hexadecimal
int my_putnbr_base_li(long int nb, char *);

//put short number with diffent base
int my_putnbr_base_hi(int nb, char *);

//put short numbers
int my_putnbr_hi(short nb);

//putnbr in different base
int my_putnbr_base(unsigned int nb, char *);

//put pointer in hex base
int display_p_in_hex(void *);

//used for float function to do power function
long int pui(long int, int);

long int pui_neg(long int, int);

//absolute value
double my_abs(double);

//all ap file call fonction with va_arg and type of fonction
//exemple with my_putchar_ap do : my_putchar(va_arg(ap, char));
int my_putchar_ap(va_list);

int my_putstr_ap(va_list);

int my_putnbr_ap(va_list);

int my_putnbr_hex_ap(va_list);

int my_putnbr_hex_ap_cap(va_list);

int my_putnbr_un_ap(va_list);

int my_putnbr_bin_ap(va_list);

int my_putnbr_li_ap(va_list);

int my_putnbr_hex_li_ap(va_list);

int my_putnbr_hex_li_ap_cap(va_list);

int my_putnbr_science_ap(va_list ap);

int my_putnbr_float_ap(va_list ap);

int my_putnbr_hex_hi_ap(va_list);

int my_putnbr_hex_hi_ap_cap(va_list);

int my_putnbr_bin_hi_ap(va_list);

int my_putnbr_bin_li_ap(va_list ap);

int my_putnbr_hi_ap(va_list);

int my_putnbr_oc_ap(va_list ap);

int my_putnbr_hex_hash_ap(va_list ap);

int my_putnbr_hex_hash_cap_ap(va_list ap);

int my_putnbr_bin_hash_ap(va_list ap);

int my_putnbr_oc_hash_ap(va_list ap);

int my_putstr_printable_ap(va_list ap);

int my_putnbr_bin_hash_cap_ap(va_list ap);

int display_p_in_hex_ap(va_list ap);

int my_putnbr_science_maj_ap(va_list ap);

//definition of strcut with c = flag
typedef struct function_s {
    char c;
    int (*ptr)(va_list);
} function_t;

#endif /* !MY_H_ */
