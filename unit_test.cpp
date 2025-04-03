#include <iostream>
#include <cstdio>
#include <memory>
#include <sstream>
#include <string>
#include <array>

std::string executeCommand(const std::string& command) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen((command + " 2>&1").c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

#define ASSERT(condition, message) \
    if (!(condition)) \
    { \
        std::cerr << RED "[FAILED] " << message RESET << " (" \
            << __FILE__ << ":" << __LINE__ << ")" << std::endl; \
        return false; \
    } \
    else \
    { \
        std::cout << GREEN "[PASSED] " << message RESET << std::endl; \
    }

#define CHECK(cond, msg) \
    if (!(cond)) { errors << "[FAILED] " << msg << "\n"; passed = false; }

bool test_empty();
bool test_invalid_input();
bool test_duplicates();
bool test_large_numbers();

int main()
{
    test_empty();
    test_invalid_input();
    test_duplicates();
    test_large_numbers();
}

bool test_empty()
{
    std::ostringstream errors;
    bool passed = true;

    std::string arg = "./push_swap";
    std::string res = executeCommand(arg);
    std::cout << "Output: " << res << std::endl;

    CHECK(res.empty(), "Push_swap should not return an error code");
    if (!passed)
	{
		std::cerr << RED "[FAILED] " << "Empty input test" RESET << std::endl;
	}
	ASSERT(passed, "[SUCCESS] Empty input test")
	return passed;
}

bool test_invalid_input()
{
    std::ostringstream errors;
    bool passed = true;

    std::string arg = "./push_swap a 111a11";
    std::string res = executeCommand(arg);
    CHECK(res.find("Error") != std::string::npos, "Push_swap should return an error for invalid input");
    if (!passed)
	{
		std::cerr << RED "[FAILED] " << "Push_swap should return an error for invalid input" RESET << std::endl;
	}
	ASSERT(passed, "[SUCCESS] Push_swap should return an error for invalid input")
	return passed;
}

bool test_duplicates()
{
    std::ostringstream errors;
    bool passed = true;

    std::string arg = "./push_swap 42 42";
    std::string res = executeCommand(arg);
    CHECK(res.find("Error") != std::string::npos, "Push_swap should return an error for duplicate numbers");
    if (!passed)
	{
		std::cerr << RED "[FAILED] " << "Push_swap should return an error for duplicate numbers" RESET << std::endl;
	}
	ASSERT(passed, "[SUCCESS] Push_swap should return an error for duplicate numbers")
	return passed;
}

bool test_large_numbers()
{
    std::ostringstream errors;
    bool passed = true;

    std::string arg = "./push_swap 2147483647 -2147483649 0";
    std::string res = executeCommand(arg);
    CHECK(res.find("Error") != std::string::npos, "Push_swap should handle large numbers correctly");
    if (!passed)
	{
		std::cerr << RED "[FAILED] " << "Push_swap should handle large numbers correctly" RESET << std::endl;
	}
	ASSERT(passed, "[SUCCESS] Push_swap should handle large numbers correctly")
	return passed;
}