/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:43:21 by fjenae            #+#    #+#             */
/*   Updated: 2019/07/09 19:19:10 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_box_print(t_dimensions *d, int size)
{
    int m;
    int n;

    m = 0;
    n = 0;
    while (m != size)
    {
        while (n != size)
        {
            printf("%c", d->box[m][n]);
            n++;
        }
        n = 0;
        printf("\n");
        m++;
    }
}

static void ft_relative_coords(t_tetris *sh_coord, int relative_coords[2][4], t_dimensions *d, char     *sequence)
{
    int     m;
    int     n;

    m = 0;
    n = 0;
        while (m != 4)
        {
            relative_coords[0][m] = sh_coord[sequence[d->l] - 65].y[0] - sh_coord[sequence[d->l] - 65].y[m];
            m++;
        }
        while (n != 4)
        {
            relative_coords[1][n] = sh_coord[sequence[d->l] - 65].x[0] - sh_coord[sequence[d->l] - 65].x[n];
            n++;
        }

}

void        clear_tetr(t_tetris *sh_coord, t_dimensions *d, char letter)
{
    int     m;
    int     n;

    m = 0;
    n = 0;
    while (m < d->size)
    {
        while (n < d->size)
        {
            if (d->box[m][n] == letter)
                d->box[m][n] = '.';
            n++;
        }
        n = 0;
        m++;
    }
}

int     ft_attempt_write(t_tetris *sh_coord, t_dimensions *d, char    *sequence)
{
    int m;
    int n;
    int relative_coords[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

    m = 0;
    n = 0;
    ft_memset(relative_coords, 0, sizeof(relative_coords));

    ft_relative_coords(sh_coord, relative_coords, d, sequence);


    printf("call of relative coords again in main body function ft_attempt_write\n");
    while (n != 4)
    {
        printf("%i\n", relative_coords[0][n]);
        n++;
    }
    printf("next\n");
    n = 0;
    while (n != 4)
    {
        printf("%i\n", relative_coords[1][n]);
        n++;
    }
    printf("next\n");

    n = 0;
    printf("printing array without first figure\n");
    ft_box_print(d, d->size);
    while (n < 4)
    {
        if ((d->n - relative_coords[0][n]) < 0 || (d->m - relative_coords[0][n]) >= d->size
            || (d->n - relative_coords[1][n]) >= d->size)
        {
//            clear_tetr(sh_coord, d, sequence[d->l]);
            return (0);
        }
        if (d->box[d->m - relative_coords[0][n]][d->n - relative_coords[1][n]] == '.')
        {
            d->box[d->m - relative_coords[0][n]][d->n - relative_coords[1][n]] = sequence[d->l];
        }
        else
        {
//            clear_tetr(sh_coord, d, sequence[d->l]);
            return (0);
        }
        n++;
    }
    printf("printing array with first figure\n");
    ft_box_print(d, d->size);
    printf("\n");
    m = 0;
    n = 0;
    return (1);
}



int     ft_placement(t_tetris *sh_coord, t_dimensions *d, char *sequence, int one_more_figure)
{
    int m;
    int n;

    m = 0;
    n = 0;
    if(one_more_figure >= d->N)
        return (1);
    if (one_more_figure == 0)
        one_more_figure = 0;
    ft_box_print(d, d->size);

        while (m < d->size)
        {
            n = 0;
            while (n < d->size)
            {
                    d->litera = 'A' + one_more_figure;
                    d->n = n;
                    d->m = m;
                    d->l = one_more_figure;
                    if(ft_attempt_write(sh_coord, d, sequence) && ft_placement(sh_coord, d, sequence, one_more_figure + 1))
                            return (1);
                    else
                        clear_tetr(sh_coord, d, sequence[d->l]);
                n++;
            }
            m++;
}
    return (0);
}

void         worker(t_tetris *sh_coord, t_dimensions *d, char *sequence)
{
    while (!ft_placement(sh_coord, d, sequence, 0))
        d->size++;
}