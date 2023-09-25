#include "main.h"
/**
* _printf - prints the standard formatted text
* @format: format specifier
* Return: number of bytes printed
*/

int _printf(const char *format, ...)
{
int i, j, c;
va_list args;

va_start(args, format);

for (i = 0; format[i] != '\0'; i++)
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
case 's':
{
char *str = va_arg(args, char *);
if (str != NULL)
{
while (*str)
{
_putchara(*str);
str++;
}
}
else
{
char nullStr[] = "(null)";
for (j = 0; nullStr[j] != '\0'; j++)
{
_putchara(nullStr[j]);
}
}
break;
}
case 'c':
{
c = va_arg(args, int);
_putchara((char)c);
break;
}
case '%':
_putchara('%');
break;
default:
_putchara('%');
_putchara(format[i]);
break;
}
}
}

va_end(args);
return (i);
}
