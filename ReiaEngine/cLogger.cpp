#include "cLogger.h"
#include "Windows.h"

cLogger::cLogger() {
	DEBUG_LOG("cLogger constructor called!\n");
	SetConsoleTitle(L"ReiaEngine Debug Console");
}

cLogger::~cLogger() {
	DEBUG_LOG("cLogger destructor called!\n");
}

#ifdef _DEBUG
void cLogger::Log(LoggingMessageType logType, string file, string functionName, int line, string format, ...) {
#else
void cLogger::Log(LoggingMessageType logType, string format, ...) {
#endif
	char type[11] = "[UNKNOWN]";
	char buffer[256];

	int bgColor = 100;
	int fgColor = 97; // white text

	switch (logType) {
	default:
	case Debug:
		strncpy(type, "[DEBUG]", 8);
		break;
	case Info:
#ifdef _DEBUG
		strncpy(type, "[INFO]", 7);
#else
		strncpy(type, "[i]\0", 4);
#endif
		bgColor = 46; // dark cyan background
		break;
	case Error:
#ifdef _DEBUG
		strncpy(type, "[ERROR]", 8);
#else
		strncpy(type, "[x]\0", 4);
#endif
		bgColor = 41;
		break;
	case Warning:
#ifdef _DEBUG
		strncpy(type, "[WARNING]", 9);
#else
		strncpy(type, "[w]\0", 5);
#endif
		bgColor = 43;
		fgColor = 30;
		break;
	}

	va_list argptr;
	va_start(argptr, format);
	vsnprintf(buffer, 255, format.c_str(), argptr);
	va_end(argptr);

#ifdef _DEBUG
	printf("\x1B[%im\x1B[%im%s\x1B[0m (%s - %s:%i): %s", bgColor, fgColor, type, file.c_str(), functionName.c_str(), line, buffer);
#else
	if (logType != Debug)
		printf("\x1B[%im\x1B[%im%s\x1B[0m %s", bgColor, fgColor, type, buffer);
	else
		printf("%s", buffer);
#endif
}