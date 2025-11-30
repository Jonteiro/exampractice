#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
    char	c;
	
	c = fgetc(f);
	while (c != EOF && isspace((unsigned char)c))
		c = fgetc(f);
	if (c == EOF)
		return (-1);
	ungetc(c, f);
    return (1);
}

int match_char(FILE *f, char c)
{
	char	p;
	
	p = fgetc(f);
	if (p == EOF)
		return (-1);
	if (p != c)
	{
		ungetc(p, f);
		return (0);
	}
    return (1);
}

int scan_char(FILE *f, va_list ap)
{
    char	c;
	char	*p;

	c = fgetc(f);
	if (c == EOF)
		return (-1);
	p = va_arg(ap, char *);
	*p = c;
    return (1);
}

int scan_int(FILE *f, va_list ap)
{
	long res = 0;
	int	sign = 1;
	int	read_any = 0;
	int	c;
	int	*r;

	c = fgetc(f);
	if (c == EOF)
		return (-1);
	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign = -1;
		c = fgetc(f);
	}
	while (c != EOF && isdigit((unsigned char)c))
	{
		res = res * 10 + (c - '0');
		read_any = 1;
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	if (!read_any)
		return (0);
	r = va_arg(ap, int *);
	*r = (int)(res * sign);
	return (1);
}

int scan_string(FILE *f, va_list ap)
{
    int	i = 0;
	int	c;
	char *s;

	c = fgetc(f);
	while (c != EOF && isspace((unsigned char)c))
		c = fgetc(f);
	if (c == EOF)
		return (-1);
	s = va_arg(ap, char *);
	while (c != EOF && !isspace((unsigned char)c))
	{
		s[i++] = (char)c;
		c = fgetc(f);
	}
	s[i] = '\0';
	if (c != EOF)
		ungetc(c, f);
    return (i > 0 ? 1 : 0);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	if (ferror(f))
		return EOF;
	return nconv;
}

int ft_scanf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}

#include <stdio.h>

int ft_scanf(const char *format, ...);

int main(void)
{
    int     n;
    char    str[100];
    char    c;

    printf("Enter an int, a word, and a char (e.g. \"42 hello X\"): \n");

    int ret = ft_scanf("%d %s %c", &n, str, &c);

    printf("\n---- Results ----\n");
    printf("Return value : %d\n", ret);
    printf("Integer      : %d\n", n);
    printf("String       : %s\n", str);
    printf("Char         : %c\n", c);

    return 0;
}
