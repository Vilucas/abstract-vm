#ifndef VM_HPP
#define VM_HPP

#include <unistd.h>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>
#include <algorithm>

#include "exception.hpp"

#define print(n) (std::cout << "value = '" << n << "'" << std::endl)
#define usage "[usage]: ./abstracrt_vm path_to_instructions_file"
bool    parsing(std::string &line, size_t line_count);

#endif