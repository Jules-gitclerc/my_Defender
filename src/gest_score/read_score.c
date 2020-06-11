/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** read_score
*/

#include "defender.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char **recup_score(void)
{
    int fd = open("./ressource/score/score", O_RDONLY);
    char *str = malloc(sizeof(char) * 32000);
    int read_c = 0;
    char **score_board = NULL;

    if (str == NULL)
        return (NULL);
    read_c = read(fd, str, 32000);
    str[read_c] = '\0';
    score_board = my_str_to_word_array(str, ' ');
    free (str);
    return (score_board);
}

int fill_score_board(score *sc)
{
    int nsc = sc->score_new;
    int tmp = 0;

    for (int i = 0; sc->score_board[i] != NULL; i++)
        if (my_getnbr(sc->score_board[i]) < nsc) {
            tmp = my_getnbr(sc->score_board[i]);
            free(sc->score_board[i]);
            sc->score_board[i] = my_supergetnbr(nsc);
            nsc = tmp;
        }
    return (0);
}

//plus qua ecrit dans le fichier le nouveau score boar