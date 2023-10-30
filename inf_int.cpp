#include "inf_int.h"


inf_int::inf_int()
{
	digits = new char[1];
	digits[0] = '0';
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


//inf_int operator+(const inf_int& lhs, const inf_int& rhs) {
//    if (!lhs.thesign && !rhs.thesign) { // Both numbers are negative
//        inf_int abs_lhs = lhs;
//        abs_lhs.thesign = true;
//        inf_int abs_rhs = rhs;
//        abs_rhs.thesign = true;
//        inf_int result = abs_lhs + abs_rhs;
//        result.thesign = false;
//        return result;
//    } else if (!lhs.thesign) { // lhs is negative
//        inf_int abs_lhs = lhs;
//        abs_lhs.thesign = true;
//        return rhs - abs_lhs;
//    } else if (!rhs.thesign) { // rhs is negative
//        inf_int abs_rhs = rhs;
//        abs_rhs.thesign = true;
//        return lhs - abs_rhs;
//    }
//    
//    // Now, we know both numbers are positive.
//    inf_int result;
//
//    int len_lhs = lhs.length;
//    int len_rhs = rhs.length;
//    int max_len = (len_lhs > len_rhs) ? len_lhs : len_rhs;
//
//    char* sum = nullptr;
//    
//    try {
//        sum = new char[max_len + 2](); // +1 for potential carry, +1 for '\0'
//    } catch (std::bad_alloc&) {
//        std::cerr << "Memory allocation failed for sum in operator+." << std::endl;
//        exit(1);
//    }
//
//    int carry = 0;
//
//    for (int i = 0; i < max_len; i++) {
//        int digit_lhs = (i < len_lhs) ? lhs.digits[i] - '0' : 0;
//        int digit_rhs = (i < len_rhs) ? rhs.digits[i] - '0' : 0;
//
//        int current_sum = digit_lhs + digit_rhs + carry;
//        sum[i] = (current_sum % 10) + '0';
//        
//        carry = current_sum / 10;
//    }
//
//    if (carry) {
//        sum[max_len] = carry + '0';
//        max_len++;
//    }
//    sum[max_len] = '\0';
//
//    result.digits = sum;
//    result.length = max_len;
//    result.thesign = true;
//
//    return result;
//}

ostream& operator<<(ostream& out, const inf_int& num)
{
	char*	p = new char[num.length + ((num.thesign) ? 0 : 1) + 1];
	int		i = 0;
	int		l = num.length + ((num.thesign) ? 0 : 1);

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


