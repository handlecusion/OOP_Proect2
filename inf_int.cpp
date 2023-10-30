// inf_int.cpp
// operator '+'
inf_int operator+(const inf_int& lhs, const inf_int& rhs) {
    if (!lhs.thesign && !rhs.thesign) { // Both numbers are negative
        inf_int abs_lhs = lhs;
        abs_lhs.thesign = true;
        inf_int abs_rhs = rhs;
        abs_rhs.thesign = true;
        inf_int result = abs_lhs + abs_rhs;
        result.thesign = false;
        return result;
    } else if (!lhs.thesign) { // lhs is negative
        inf_int abs_lhs = lhs;
        abs_lhs.thesign = true;
        return rhs - abs_lhs;
    } else if (!rhs.thesign) { // rhs is negative
        inf_int abs_rhs = rhs;
        abs_rhs.thesign = true;
        return lhs - abs_rhs;
    }
    
    // Now, we know both numbers are positive.
    inf_int result;

    int len_lhs = lhs.length;
    int len_rhs = rhs.length;
    int max_len = (len_lhs > len_rhs) ? len_lhs : len_rhs;

    char* sum = nullptr;
    
    try {
        sum = new char[max_len + 2](); // +1 for potential carry, +1 for '\0'
    } catch (std::bad_alloc&) {
        std::cerr << "Memory allocation failed for sum in operator+." << std::endl;
        exit(1);
    }

    int carry = 0;

    for (int i = 0; i < max_len; i++) {
        int digit_lhs = (i < len_lhs) ? lhs.digits[i] - '0' : 0;
        int digit_rhs = (i < len_rhs) ? rhs.digits[i] - '0' : 0;

        int current_sum = digit_lhs + digit_rhs + carry;
        sum[i] = (current_sum % 10) + '0';
        
        carry = current_sum / 10;
    }

    if (carry) {
        sum[max_len] = carry + '0';
        max_len++;
    }
    sum[max_len] = '\0';

    result.digits = sum;
    result.length = max_len;
    result.thesign = true;

    return result;
}
