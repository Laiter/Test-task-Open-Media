#ifndef LAITER_COMPARE_FILES_H
#define LAITER_COMPARE_FILES_H
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>

namespace laiter {
	bool CompareFiles(const std::string& file1, const std::string& file2);
} // namespace laiter
#endif
