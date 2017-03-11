#include "compare_files.h"

namespace laiter {
	bool CompareFiles(const std::string& file1, const std::string& file2)
	{
		std::ifstream fin1(file1, std::ios::binary);
		std::ifstream fin2(file2, std::ios::binary);
		std::ifstream::pos_type size1, size2;

		size1 = fin1.seekg(0, std::ifstream::end).tellg();
		fin1.seekg(0, std::ifstream::beg);

		size2 = fin2.seekg(0, std::ifstream::end).tellg();
		fin2.seekg(0, std::ifstream::beg);

		if (size1 != size2)
		{
			fin1.close();
			fin2.close();
			return false;
		}

		const size_t buffer_size = 4096;
		size_t remaining = size1;

		while (remaining)
		{
			char buffer1[buffer_size], buffer2[buffer_size];
			size_t size = std::min(buffer_size, remaining);

			fin1.read(buffer1, size);
			fin2.read(buffer2, size);

			if (0 != std::memcmp(buffer1, buffer2, size))
			{
				fin1.close();
				fin2.close();
				return false;
			}
			remaining -= size;
		}
		fin1.close();
		fin2.close();
		return true;
	}
} // namespace laiter
