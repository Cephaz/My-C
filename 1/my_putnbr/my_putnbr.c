/*
** ETNA PROJECT, 30/09/2019 by zhou_p
** putnbr 
** File description:
**              nbrnbr...
*/

void my_putchar(char c);

void my_putnbr(int n)
{
        if (-2147483648 == n) {
                my_putchar('-');
                my_putchar('2');
                n = 147483648;
                my_putnbr(n);
        } else {
                if (n < 0) {
                        my_putchar('-');
                        n = n * -1;
                }
                if (n >= 10) {
                        my_putnbr(n / 10);
                }
                my_putchar(n % 10 + '0');
        }
}
