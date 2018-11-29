/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** test
*/

void my_hunter(void);
void check_args(int ac, char **av, char **env);

int main(int ac, char **av, char **env)
{
    check_args(ac, av, env);
    my_hunter();
    return (0);
}
