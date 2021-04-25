#pragma once

#define _CRT_SECURE_NO_WARNINGS

enum LoggingMessageType {
	Debug,
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

#ifdef _DEBUG
	void Log(LoggingMessageType logType = Info, string file = "unknown", string functionName = "unknown", int line = -1, string format = "", ...);
#else
	void Log(LoggingMessageType logType = Info, string format = "", ...);
#endif
};

extern cLogger LoggerInstance;

#ifdef _DEBUG

#define DEBUG_LOG(...) LoggerInstance.Log(Debug, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define INFO_LOG(...) LoggerInstance.Log(Info, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define ERROR_LOG(...) LoggerInstance.Log(Error, __FILE__, __func__, __LINE__, __VA_ARGS__)
#define WARN_LOG(...) LoggerInstance.Log(Warning, __FILE__, __func__, __LINE__, __VA_ARGS__)

#else

#define DEBUG_LOG(...) LoggerInstance.Log(Debug, __VA_ARGS__)
#define INFO_LOG(...) LoggerInstance.Log(Info, __VA_ARGS__)
#define ERROR_LOG(...) LoggerInstance.Log(Error, __VA_ARGS__)
#define WARN_LOG(...) LoggerInstance.Log(Warning, __VA_ARGS__)

#endif

#endif