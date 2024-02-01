#include "Fixed.hpp"

int		main(void)
{
	Fixed b( 10 );
	Fixed const c( 42.42f );
	Fixed const d(b * c);
	Fixed const e(b - c);
	Fixed const f(c / b);

	std::cout << "Value of d: " << d << std::endl;
	std::cout << "Value of e: " << e << std::endl;
	std::cout << "Value of f: " << f << std::endl;
	std::cout << ++b << std::endl;
	std::cout << b << std::endl;
}

// int main( void ) {
// 	Fixed a (5);
// 	Fixed const b( a / a );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, a ) << std::endl;
// 	return 0;
// }
