/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** test
*/

void my_hunter(void);
int check_args(int ac, char **av, char **env);

int main(int ac, char **av, char **env)
{
    if (check_args(ac, av, env) != 0)
        return (84);
    my_hunter();
    return (0);
}
