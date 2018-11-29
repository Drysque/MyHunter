/*
** EPITECH PROJECT, 2018
** my_usage.c
** File description:
** prints the usage for my_hunter
*/

#include <stdlib.h>
#include <unistd.h>

static int my_strlen(char const *str)
{
    int len = 0;

    for (int i = 0; str[i]; i++)
        len++;
    return (len);
}

void my_usage(int ac, char **av)
{
    char usage[] = "USAGE: \n\t./my_hunter\n\n";
    char description[] = "DESCRIPTION:\n\tPress SPACE to start\n";
    char bird[] = "\tPress right click to hunt the birds\n";
    char difficulty[] = "\tThe more you kill, the harder it gets!\n";
    char failure[] = "\tIf you fail to kill one, you loose a life...\n";
    char fun[] = "\tHave fun!\n";

    if (ac != 1) {
        write(1, usage, my_strlen(usage));
        write(1, description, my_strlen(description));
        write(1, bird, my_strlen(bird));
        write(1, difficulty, my_strlen(difficulty));
        write(1, failure, my_strlen(failure));
        write(1, fun, my_strlen(fun));
        exit (0);
    }
}
