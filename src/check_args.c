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

static int my_usage(int ac, char **av)
{
    char usage[] = "USAGE: \n\t./my_hunter\n\n";
    char description[] = "DESCRIPTION:\n\tPress SPACE to start\n";
    char bird[] = "\tPress left click to hunt the birds\n";
    char difficulty[] = "\tThe more you kill, the harder it gets!\n";
    char failure[] = "\tIf you fail to kill one, you loose a life...\n";
    char quit[] = "\tPress Escape to quit\n";
    char fun[] = "\tHave fun!\n";

    write(1, usage, my_strlen(usage));
    write(1, description, my_strlen(description));
    write(1, bird, my_strlen(bird));
    write(1, difficulty, my_strlen(difficulty));
    write(1, failure, my_strlen(failure));
    write(1, quit, my_strlen(quit));
    write(1, fun, my_strlen(fun));
    return (1);
}

static int my_null_env(void)
{
    char error[] = "error\n";
    char try[] = "Nice try, but the program can't be ";
    char env[] = "used with an empty environment!\n";

    write(2, error, my_strlen(error));
    write(1, try, my_strlen(try));
    write(1, env, my_strlen(env));
    return (84);
}

int check_args(int ac, char **av, char **env)
{
    if (env[0] == NULL)
        return (my_null_env());
    if (ac != 1)
        return (my_usage(ac, av));
    return (0);
}
