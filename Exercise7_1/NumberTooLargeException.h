/////////////////////////////////////////////////////
// CIS554 Object Oriented Programming in C++
// Exercise 7_1 - Exception Handling  Class Interface
// Patricia Gallant
/////////////////////////////////////////////////////
#include <stdexcept> // stdexcept header contains runtime_error

// Handle errors thrown for mulitplication results greater than 1,000,000
class NumberTooLargeException : public std::runtime_error {
public:
	// constructor specifies default error message
	NumberTooLargeException()
		: std::runtime_error{ "number is too large" } {}
};


