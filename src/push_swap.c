/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amatthys <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/20 13:45:25 by amatthys     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 10:57:17 by amatthys    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "checker.h"
#include "libft/libft.h"

void	create_parse(t_parse *lap, t_parse parse)
{
	size_t	tmp;
	size_t	i;

	tmp = parse.len / 2;
	i = parse.len - tmp;
	lap[0].min = 0;
	lap[0].max = lap[0].min + i - 1;
	lap[0].len = lap[0].max - lap[0].min + 1;
	lap[0].rot = 0;
	lap[0].side = 0;
	lap[1].min = 0;
	lap[1].max = lap[1].min + tmp - 1;
	lap[1].len = lap[1].max - lap[1].min + 1;
	lap[1].rot = 0;
	lap[1].side = 1;
}

void	init_tab(t_tab *taba, t_tab *tabb, t_parse *parse, t_opt top)
{
	taba->len = top.len;
	tabb->len = 0;
	tabb->tab = (int *)malloc(sizeof(int) * (top.len));
	parse->min = 0;
	parse->max = top.len - 1;
	parse->side = 0;
	parse->rot = 0;
	parse->len = parse->max - parse->min + 1;
	parse->med = find_median(taba, tabb, *parse);
}

int		main(int argc, char **argv)
{
	t_tab		taba;
	t_tab		tabb;
	t_opt		top;
	t_parse		parse;

	if (!check_file(argc, argv))
		return (0);
	if (!(taba.tab = create_tab(argc, argv, &top)))
		return (print_error());
	init_tab(&taba, &tabb, &parse, top);
	if (taba.len == 3 || taba.len == 5)
		sort_spec(&taba, &tabb);
	else if (!is_sort(&taba))
		split(&taba, &tabb, parse);
	while (tabb.len)
		print_do(&taba, &tabb, "pa");
	free(taba.tab);
	free(tabb.tab);
	write(1, "\0", 1);
	return (1);
}
