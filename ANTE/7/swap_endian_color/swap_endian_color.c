/*
** ETNA PROJECT, 07/10/2019 by zhou_p
** swap_endian_color.c
** File description:
**      Code is poetry..
*/

int swap_endian_color(int color)
{
	return 
        ((color & 0xFF000000) >> 24) | ((color & 0x00FF0000) >> 8) |
		((color & 0x0000FF00) << 8) | ((color & 0x000000FF) << 24);
}
