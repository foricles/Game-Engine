#ifndef _UTILS_H_
#define _UTILS_H_

#include "Logger.h"

namespace utils
{
#define MY_PI 3.1415926535897932f
	namespace file
	{
		inline const char *load_file(const char *filepath, const char* mode = "rt")
		{
			FILE *file = fopen(filepath, mode);
			if (file == nullptr)
			{
				Logger::Log("Can not open " + std::string(filepath), LogType::ERR);
				return nullptr;
			}
			fseek(file, 0, SEEK_END);
			unsigned int length = ftell(file);
			char* text = new char[length + 1];
			memset(text, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(text, sizeof(char), length, file);
			fclose(file);
			return text;
		}
	}

	namespace math
	{
		inline float to_radian(float x) { return ( x * MY_PI / 180.0f); }
		inline float to_degree(float x) { return ( x * 180.0f / MY_PI); }
	}
}

#endif // !_UTILS_H_
