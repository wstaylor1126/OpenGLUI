//--Log.cpp
#include "Log.h"

void Log::Write(std::string dialogue, int newLine)
{
	newLine == 0 ? log.push_back(dialogue) : log.push_back(dialogue + '\n');
}

void Log::Dump()
{
	if (log.size() == 0)
	{
#ifdef _SLIB_LOG_DEBUG_ERR_
		std::cout << name << " is empty, Dump() returned void." << std::endl;
#endif
		return;
	}
	std::ofstream logOut;
	logOut.open(exportPath);
	for (int i = 0; i < log.size(); i++)
	{
		std::string tmp = log[i];
			logOut.write(tmp.c_str(), tmp.size());
	}
	logOut.close();
}

void Log::Read()
{
	if (log.size() == 0)
	{
#ifdef _SLIB_LOG_DEBUG_ERR_
		std::cout << name << " is empty, Read() returned void." << std::endl;
#endif
		return;
	}
	for (int i = 0; i < log.size(); i++)
	{
		std::cout << log[i];
	}
}

Log::Log(const char* path, const char* nameOpt)
{
	exportPath = path;
	name = nameOpt;
}
Log::~Log() = default;