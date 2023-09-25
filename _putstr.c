#include "main.h"
/**
 * _putstr - printing a string
 * @str: the string
 * Return: an int
 */

int _putstr(char *str)
{
    int n;

    if (str)
    {
        for (n = 0; str[n] != '\0'; n++)
        {
            _putchara(str[n]);
        }
    }
    return (n);
}
