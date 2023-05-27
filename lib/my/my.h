/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

#include <stdarg.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "struct.h"

#ifndef MY_H_

    #define MY_H_

    int my_putchar(char c);
    int my_isneg(int nb);
    int my_put_nbr(long nb, int count);
    void my_swap(int *a, int *b);
    void my_swap_char(char **a, char **b);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_strlen_double(char *const *str);
    int my_getnbr(char const *str);
    void my_sort_int_array(int *tab, int size);
    int my_compute_power_rec(int nb, int power);
    int my_compute_square_root(int nb);
    int my_is_prime(int nb);
    int my_find_prime_sup(int nb);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_revstr(char *str);
    char *my_strstr(char *str, char const *to_find);
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
    int my_showstr(char *str);
    int my_showmem(char const *str, int size);
    char *my_strcat(char *dest, char const *src);
    char *my_strncat(char *dest, char const *src, int nb);

    int digits_in_number(int d);
    void space_less(var_t var, int *result, int result_base);
    int my_putfloat(double nb, int n);
    int my_printf(const char *format, ...);
    int my_printf2(var_t var, const char *format, va_list ap, int *result);
    int specifier(var_t var, const char *format, va_list ap, int *result);
    int specifier_space(var_t var,const char *format,
    va_list ap, int *result);
    int specifier_more(var_t var, const char *format, va_list ap, int *result);
    int specifier_less(var_t var, const char *format, va_list ap, int *result);
    int specifier_less6(var_t var, const char *format, va_list ap, int *result);
    int specifier_zero(var_t var, const char *format, va_list ap, int *result);
    int specifier_hashtag(var_t var, const char *format,
    va_list ap, int *result);
    int s_flag(char *str);
    int e_flag(double nb, int n);
    int e_flag_zero(double nb, int n);
    int upper_e_flag(double nb, int n);
    int e_flag_hashtag(double nb, int n);
    int upper_e_flag_hashtag(double nb, int n);
    int my_put_ptr(unsigned int nbr, int count);
    int flag(var_t var, const char *format, va_list ap, int *result);
    int check_flags(char c);
    int check_flags2(char c);
    int my_char_isnum(char str);
    void space_zero(var_t var, int *result, int result_base);
    int my_put_nbr_zero(int nbr, int count);
    int my_putnbr_base_zero(unsigned int nbr, char *base, int count);
    int my_put_ptr_zero(unsigned int nbr, int count);
    void specifier_zero6(var_t var, const char *format,
    va_list ap, int *result);
    int zero_before(char *array, int count);
    int zero_before_zero(char *array, int count);
    int s_flag_zero(char *str);
    int specifier_point(var_t var, const char *format,
    va_list ap, int *result);
    void specifier_point6(var_t var, const char *format,
    va_list ap, int *result);
    int my_putstr_zero(char const *str);
    void reset_array(char *array);
    int my_putnbr_base_s(unsigned int nbr, char *base, int count, char *array);
    int specifier_nbr(var_t var, const char *format,
    va_list ap, int *result);
    int s_flag_point(var_t var, char *str);
    int my_putstr_point(var_t var, char const *str);
    int specifier_nbr6(var_t var, const char *format, va_list ap, int *result);
    int flag3(var_t var, const char *format, va_list ap, int *result);
    int flag4(var_t var, const char *format, va_list ap, int *result);
    int flag6(var_t var, const char *format, va_list ap, int *result);
    int get_width(var_t var, const char *format, char *array);
    int specifier_hashtag_point(var_t var,
    const char *format, va_list ap, int *result);
    int specifier_hashtag_point6(var_t var,
    const char *format, va_list ap, int *result);
    int specifier_hashtag3(var_t var,
    const char *format, va_list ap, int *result);
    int specifier_long(var_t var, const char *format, va_list ap, int *result);
    int my_putnbr_base_long(unsigned long nbr, char *base, int count);
    int my_putfloat_zero(double nb, int n);
    void flag4_2(var_t var, const char *format, va_list ap, int *result);

    int my_is_prime2(int nb);
    int int_at(int index, char *tab);
    long power10(int len);
    int str_to_int(char *tab, int len, int negative);
    int my_compute_square_root2(int nb);
    int my_putnbr_base(unsigned int nbr, char *base, int count);
    int middle(char *str);
    int my_swapstr(char *a, char *b);
    void hexa(int i, char *str);
    void check_separator_lower(int i, char *str);
    void check_separator_upper(int i, char *str);
    int check_isalpha(int i, char *str);

    int my_ls(char *flag, char *path, int multi);
    char *l_flag(struct dirent *dirent, char* file);
    int l_flag_len(char* file);
    int check_flag(char *flag, char c);
    char *generate_char_flag(int argc, char **argv);
    int total_l(char *path, char *flag);
    void owner(char* file, char *rwx);
    void group(char* file, char *rwx);
    void other(char* file, char *rwx);
    char *my_strdup(char const *src);
    int my_show_word_array(char *const *tab);
    int my_show_word_array_rev(char *const *tab);
    int my_put_nbr_count(long nbr, int count);
    int int_to_str(long nbr, int count, char *str);
    char **add_files_l(char **result, char *file_l, int i);
    char **total_files(char *flag, char *path);
    void add_perm(char *file, char *result);
    void add_number(int number, char *result);
    void add_time(char *result, const time_t *timer);
    void add_owner_group(char *result, uid_t uid, gid_t gid);
    void type(char* file, char *rwx);
    void my_sort_time_array(char **tab, char *path);
    int my_sort_alphabet_array(char **tab);
    char *new_file(char *path, char *file);
    int my_strcmp_ignore_case(char const *s1, char const *s2);
    char **add_files(char **result, struct dirent *file, int i);
    int is_directory(const char *path);
    int l_flag_len_link(char* file, struct stat st);
    char *l_flag_link(char *result, char* file3, struct stat st);
    char **my_sort_word_array_rev(char **tab);
    void my_sort_time_array_dir(char **tab);
    int middle_double(char **str);
    int flag_d(char *path, char *flag);
    int my_sort_alphabet_array_l(char **tab, char **tab2);
    void my_sort_time_array_l(char **tab, char **tab2, char *path);
    void flag_upperr(char *flag, char **result, char **result_l, char *path);
    char **my_strdup_double(char **src);
    char *l_flag_only(char *file);
    void print_ls_manage(char *flag, char **result,
    char *path, char **result_l);
    int specific(char *path, char *flag);
    int is_existing(const char *path);
    int first_path2(int is_first_path2);

#endif /* MY_H_ */
