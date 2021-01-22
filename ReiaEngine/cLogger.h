#pragma once

#define _CRT_SECURE_NO_WARNINGS

enum LoggingMessageType {
	Info,
	Error,
	Warning
};

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <stdio.h>
#include <cstdarg>

using namespace std;

class cLogger
{
public:
	cLogger();
	~cLogger();

	void Log(LoggingMessageType logType = Info, string file = "unknown", string functionName = "unknown", int line = -1, string message = "", ...);
};

extern cLogger LoggerInstance;

#define INFO_LOG(...) LoggerInstance.Log(Info, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define ERROR_LOG(...) LoggerInstance.Log(Error, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define WARN_LOG(...) LoggerInstance.Log(Warning, __FILE__, __func__, __LINE__, __VA_ARGS__)

#endif