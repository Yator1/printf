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
        }
        else
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    _putchara(va_arg(argument, int));
                    break;
                case 's':
                    s_counter = _putstr(va_arg(argument, char *));
                    counter += (s_counter - 1);
                    break;
                case '%':
                    _putchara('%');
                    break;
            }
        }
        counter += 1;
    }
    return(counter);
}