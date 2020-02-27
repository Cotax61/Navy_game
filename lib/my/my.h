/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** print the alphabet in ascending order
*/

#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_usage(int a, int b);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_add(int a, int b);
int my_sub(int a, int b);
int my_mul(int a, int b);
int my_div(int a, int b);
int my_mod(int a, int b);
char tocase(char c);
int my_ret_message(char *str, int ret);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strdup(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str, int size);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strstr(char *str, char const *find);
char *my_strncat(char *dest, char const *src, int n);
char **my_str_to_word_array(char *str);
void my_put_error(char *str);
void my_put_array(char **array, int line_jump, int end_jump);
char icase(char c);

#endif /* MY_H */