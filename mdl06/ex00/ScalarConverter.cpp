#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cctype>

bool isChar(const std::string& s)
{
	return s.length() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
}


bool isInt(const std::string& s)
{
    if (s.empty() || std::isspace(s[0]))
        return false;

    char *end;
    errno = 0;
    long n = std::strtol(s.c_str(), &end, 10);
    return *end == '\0' && errno != ERANGE && n >= INT_MIN && n <= INT_MAX;
}


bool isDouble(const std::string& s)
{
	if(s.empty() || std::isspace(s[0]))
		return false;
	if(s == "nan" || s == "+inf" || s == "-inf" || s == "inf")
		return true;
	size_t i = 0;
	while(s[i] && std::isspace(s[i]))
		i++;
	if(s[i] == '+' || s[i] == '-')
		i++;
	bool dot = false;
	bool digit = false;
	for(; s[i]; i++)
	{
		if(std::isdigit(s[i]))
			digit = true;
		else if(s[i] == '.' && !dot)
			dot = true;
		else
			return false;
	}
	return digit;
}

static bool isFloat(const std::string& s)
{
    if (s.empty() || std::isspace(s[0]))
        return false;
    if (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff")
        return true;
    if (s[s.length() - 1] != 'f')
        return false;

    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;

    bool dot = false;
    bool digit = false;
    for (; s[i + 1]; i++)
    {
        if (std::isdigit(s[i]))
            digit = true;
        else if (s[i] == '.' && !dot)
            dot = true;
        else
            return false;
    }
    return digit;
}

static void printChar(double value)
{
    std::cout << "char: ";
    if (value != value || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
    std::cout << "int: ";
    if (value != value || value < INT_MIN || value > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
    float f = static_cast<float>(value);
    std::cout << "float: " << f;
    if (f > -1e6 && f < 1e6 && f == static_cast<long>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

static void printDouble(double value)
{
    std::cout << "double: " << value;
    if (value > -1e6 && value < 1e6 && value == static_cast<long>(value))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    double value;

    if (isChar(input))
        value = static_cast<double>(input[0]);
    else if (isInt(input))
        value = static_cast<double>(std::strtol(input.c_str(), NULL, 10));
    else if (isFloat(input))
        value = static_cast<double>(static_cast<float>(std::strtod(input.c_str(), NULL)));
    else if (isDouble(input))
        value = std::strtod(input.c_str(), NULL);
    else
    {
        std::cout << "Error: invalid literal" << std::endl;
        return;
    }
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}