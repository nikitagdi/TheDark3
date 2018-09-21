#include "Utils.h"
#include <Windows.h>
#include <boost/lexical_cast.hpp>

namespace TDEngine
{
	namespace Utils
	{
		std::string GetCurrentTimeString()
		{
			SYSTEMTIME Time;
			GetLocalTime(&Time);
			return boost::lexical_cast<std::string>(Time.wHour)+":"
				+boost::lexical_cast<std::string>(Time.wMinute)+":"
				+boost::lexical_cast<std::string>(Time.wSecond);
		}

	}
}