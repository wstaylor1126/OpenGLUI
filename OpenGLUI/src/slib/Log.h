//--Log.h
#pragma once
#include "sLib.h"

class Log
{
public:
	void Write(std::string dialogue, int newLine=1);
	void Dump();
	void Read();
	Log(const char* path, const char* nameOpt="Log");
	~Log();
private:
	std::vector<std::string> log;
	const char* exportPath;
	const char* name;
};