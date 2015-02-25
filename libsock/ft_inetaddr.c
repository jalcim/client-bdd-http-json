#include "ft_inet.h"

unsigned long int ft_inet_addr(const char *ip)
{
	t_in_addr addr;

	ft_inet_aton(ip, &addr);
	return(addr.s_addr);
}

int ft_inet_aton(const char *cp, t_in_addr *addr)
{
	t_aton	 	t;
    unsigned long tmp;
    
	t.c = (char *)cp;
	t.n = 0;
	t.gotend = 0;
	while (!t.gotend)
	{
		errno = 0;
        tmp = strtoul((t.c), &(t.endptr), 0);
        t.val = (in_addr_t)tmp;
		if (errno == ERANGE || t.endptr == t.c)
			return (0);
		t.parts[t.n] = t.val;
		t.c = t.endptr;
		if (t.c[0] == '.')
		{
			if (t.n == 3)
				return (0);
			t.n++;
			t.c++;
		}
		else if(t.c[0] == '\0')
			t.gotend = 1;
		else
		{
			if (isspace((unsigned char)t.c[0]))
				t.gotend = 1;
			else
				return (0);
		}

	}
	if (t.n == 1)
	{
		if (t.val > 0xffffff || t.parts[0] > 0xff)
			return (0);
		t.val |= t.parts[0] << 24;
	}
	else if (t.n == 2)
	{
		if (t.val > 0xffff ||t.parts[0] > 0xff || t.parts[1] > 0xff)
			return (0);
		t.val |= (t.parts[0] << 24) | (t.parts[1] << 16);
	}
	else if (t.n == 3)
	{
		if (t.val > 0xff || t.parts[0] > 0xff || t.parts[1] > 0xff ||
				t.parts[2] > 0xff)
			return (0);
		t.val |= (t.parts[0] << 24) | (t.parts[1] << 16) | (t.parts[2] << 8);
	}
	if (addr != NULL)
		addr->s_addr = ft_htonl(t.val);
	return (1);
}

unsigned short ft_htons(unsigned short value)
{
  return (value >> 8 | value << 8);
}

unsigned int ft_htonl(unsigned int value)
{
  char*c;

  c = (char *)&value;
  return (c[3] | c[2] << 8 | c[1] << 16 | c[0] << 24);
}
