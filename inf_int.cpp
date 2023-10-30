#include "inf_int.h"


inf_int::inf_int()
{
	digits = new char[2];
	digits[0] = '0';
	digits[1] = 0;
	length = 1;
	thesign = true;
}

inf_int::inf_int (int n)
{
	length = 0;

	if (n < 0)
	{
		n = -n;
		thesign = false;
	}
	else
		thesign = true;
	int	nbr = n;
	while (nbr)
	{
		nbr /= 10;
		length++;
	}
	digits = new char[length + 1];
	for (int i = 0; n; i++)
	{
		digits[i] = '0' + n % 10;
		n /= 10;
	}
	digits[length] = 0;

}

inf_int::inf_int (const char* str)
{
	int	len = 0;
	int	i = -1;

	while (str[len])
		++len;
	
	if (str[0] == '-')
	{
		thesign = false;
		length = --len;
		str++;
	}
	else
	{
		thesign = true;
		length = len;
	}
	digits = new char[length + 1];
	digits[len] = 0;
	while(str[++i])
		digits[len - i - 1] = str[i];
}

inf_int::inf_int(const inf_int& ii)
{
	length = ii.length;
	thesign = ii.thesign;
	digits = new char[length + 1];

	for (int i = 0; i < length; i++)
		digits[i] = ii.digits[i];

	digits[length] = 0;
}

inf_int::~inf_int()
{
	delete(digits);
}

inf_int& inf_int::operator=(const inf_int& ii)
{
	length = ii.length;
	thesign = ii.thesign;
	digits = new char[length + 1];

	for (int i = 0; i < length; i++)
		digits[i] = ii.digits[i];

	digits[length] = 0;

	return (*this);
}

void inf_int::ch_sign()
{
	thesign = !thesign;
}

inf_int operator+(const inf_int& li, const inf_int& ri)
{
    inf_int result;
    int max_len = (li.length > ri.length) ? li.length : ri.length;
	bool sign = true;
	int	sign_l = (li.thesign) ? 1 : -1;
	int sign_r = (ri.thesign) ? 1 : -1;
    char* sum = nullptr;
    try {
        sum = new char[max_len + 2]; // +1 for potential carry, +1 for '\0'
    } catch (std::bad_alloc&) {
        std::cerr << "Memory allocation failed for sum in operator+." << std::endl;
        exit(1);
    }

    int carry = 0;
    for (int i = 0; i < max_len; i++)
	{
        int digit_l = sign_l * ((i < li.length) ? li.digits[i] - '0' : 0);
        int digit_r = sign_r * ((i < ri.length) ? ri.digits[i] - '0' : 0);

        int current = digit_l + digit_r + carry;
		if (current < 0)
		{
			current *= -1;
			sign = false;
		}
		else
			sign = true;
        sum[i] = (current % 10) + '0';
        carry = current / 10;
    }
    if (carry)
        sum[max_len++] = carry + '0';
	else
	{
		cout << "exception no carry:";
	}
    sum[max_len] = '\0';

    result.digits = sum;
    result.length = max_len;
	result.thesign = sign;

    return (result);
}

inf_int operator-(const inf_int& li, const inf_int& ri)
{
	inf_int r = ri;
	r.ch_sign();
	return (li + r);
}

bool operator==(const inf_int& a, const inf_int& b)
{
	if (a.thesign != b.thesign) 
	{
		return false;
	}
	if (strcmp(a.digits, b.digits) != 0) 
	{
		return false;
	}
	return true;
}

bool operator!=(const inf_int& a, const inf_int& b)
{
	return !operator==(a, b);
}

bool operator>(const inf_int& a, const inf_int& b)
{
	if (a.thesign != b.thesign)
	{
		return a.thesign;
	}
	if (a.thesign)
	{
		return strcmp(a.digits, b.digits) > 0;
	}
	return strcmp(a.digits, b.digits) < 0;
}

bool operator<(const inf_int& a, const inf_int& b)
{
	return !operator>(a, b);
}

ostream& operator<<(ostream& out, const inf_int& num)
{
	char*	p = new char[num.length + !num.thesign];
	int		i = 0;
	int		l = num.length + !num.thesign;

	p[l] = 0;
	if (!num.thesign)
		p[i++] = '-';
	while (i < l)
	{
		p[i] = num.digits[l - i - 1];
		i++;
	}

	out << p;
	return (out);
}


