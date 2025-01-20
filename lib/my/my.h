/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** list
*/

#include <stdarg.h>
#ifndef MY_H
    #define MY_H

struct info_param {
    int length;// parameter 's length
    char *str;// parameter 's address
    char *copy;// parameter 's copy
    char **word_array;// the result of my_str_to_word_array ( str)
};

int my_putchar(char c);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strstr(char *str, char const *to_find);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int my_compute_power_it(int nb, int p);
char *switch_case(char *c);
int is_nbr(char c);
int verify(char *str, char const *to_find);
int not_nbr_ltr(char c);
int is_letter_or_number(char c);
char **my_str_to_word_array(char const *str);
int my_square_root_prime(int nb);
int count_nb_word(char const *str);
int check_length(char const *s1, char const *s2);
int my_show_word_array(char *const *tab);
struct info_param *my_param_to_array(int ac, char **av);

typedef struct {
    int prec;            // Precision
    int width;           // Width
    unsigned int is_long_double;  // L or ll flag
    unsigned int is_short;        // h flag
    unsigned int is_long;         // l flag
    unsigned int alt;             // # flag
    unsigned int space;           // Space flag
    unsigned int left;            // - flag
    unsigned int showsign;        // + flag
    unsigned int group;           // ' flag
    unsigned int is_char;         // hh flag
    unsigned int i18n;            // I flag
} specifier_t;

char *conv_to_hex(unsigned long nb);
char *conv_to_octa(int nb);
int print_hexa(va_list ap, specifier_t spe);
int print_octa(va_list ap, specifier_t spe);
int print_hexa_low(va_list ap, specifier_t spe);
int my_printf(const char *format, ...);
int print_string(va_list ap, specifier_t spe);
int print_char(va_list ap);
int print_percent(void);
int my_put_float(double nb, int spe);
int print_float(va_list ap, specifier_t spe);
void my_scient(double nb, int spe);
void my_scient_upper(double nb, int spe);
int print_a_upper(va_list ap, specifier_t spe);
int print_a_low(va_list ap, specifier_t spe);
int print_e(va_list ap, specifier_t spe);
int print_e_upper(va_list ap, specifier_t spe);
char *conv_post_coma(double nb, int spe);
int my_put_unsigned(long int nb);
char *conv_ptr(void *ptr);
int print_ptr(va_list ap);
int print_unsigned(va_list ap, specifier_t spe);
double arrondis(int power);
int len_nb(unsigned int nb);
void print_width(int width, int *count, int len);
int print_hash(char d);
int print_showsign(int nb);
int print_space(char *str, int nb);
void my_float_scient(double nb, int spe);
int print_g(va_list ap, specifier_t spe);
int my_put_float_without(double nb);

typedef int (*function_t)();

typedef struct {
    char c;
    function_t func;
} flag_function_t;

void init_tab_func(flag_function_t *f);
specifier_t init_specifier(char *specifier);
int print_int(va_list ap, specifier_t spe);
void free_word_array(char **arr);
int len_chararr(char **arr);

#endif /*my_h*/
