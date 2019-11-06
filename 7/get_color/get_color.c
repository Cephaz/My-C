/*
** ETNA PROJECT, 07/10/2019 by zhou_p
** get_color.c
** File description:
**      Code is poetry..
*/

unsigned int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
	int rgb = ((red & 0x0ff) << 16) | ((green & 0x0ff) << 8) | (blue & 0x0ff);

	return (rgb);
}
