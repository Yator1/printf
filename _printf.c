#include "main.h"
/**
* _printf - prints the standard formatted text
* @format: format specifier
* Return: number of bytes printed
*/

int _printf(const char *format, ...)
{
    int i, s_counter, counter = 0;

    va_list argument;

    va_start(argument, format);

    for (i = 0;format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            _putchara(format[i]);
            counter++;
        }
        else if (format[i + 1] == 'c')
        {
            _putchara(va_arg(argument, int));
            i++;
        }
        else if (format[i + 1] == 's')
        {
            s_counter = _putstr(va_arg(argument, char *));
            i++;
            counter += (s_counter - 1);
        }
        else if (format[i + 1] == '%')
        {
            _putchar('%');
        }
        counter++;
    }
    va_end(argument);
    return(counter);
}
