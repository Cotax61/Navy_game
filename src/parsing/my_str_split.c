/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_str_split
*/

#include <stdlib.h>
#include "main.h"
#include "my.h"

static void go_to_next_word(char **str, char sep)
{
    for (; **str == sep && **str; (*str)++);
}

static int word_len(char *str, char sep)
{
    int i = 0;

    for (i = 0; str[i] && str[i] != sep; i++);
    return (i);
}

static int count_words(char *str, char sep)
{
    int words = 0;

    while (1) {
        go_to_next_word(&str, sep);
        if (!*str)
            return (words);
        str += word_len(str, sep);
        ++words;
    }
}

static int get_new_word(char *str, char **dest, char sep)
{
    int size_word = 0;

    go_to_next_word(&str, sep);
    size_word = word_len(str, sep);
    *dest = malloc(sizeof(char) * (size_word + 1));
    if (!(*dest))
        return (-1);
    my_split_cpy(*dest, str, sep);
    return (0);
}

char **my_str_split(char *str, char sep)
{
    char **word_array = NULL;
    int is_get_success = 0;
    char *original_str = str;

    if (!str)
        return (NULL);
    word_array = malloc(sizeof(char *) * (count_words(str, sep) + 1));
    if (!word_array)
        return (NULL);
    for (int i = 0; i < count_words(original_str, sep); ++i) {
        is_get_success = get_new_word(str, word_array + i, sep);
        if (is_get_success == -1)
            return (NULL);
        go_to_next_word(&str, sep);
        str += word_len(str, sep);
    }
    word_array[count_words(original_str, sep)] = NULL;
    return (word_array);
}