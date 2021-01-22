#include "cLogger.h"

cLogger::cLogger() {
	printf("cLogger constructor called!\n");
}

cLogger::~cLogger() {
	printf("cLogger destructor called!\n");
}

void cLogger::Log(LoggingMessageType logType, string file, string functionName, int line, string format, ...) {
	char type[11] = "[UNKNOWN]";
	char buffer[256];

	int bgColor = 100;
	int fgColor = 97; // white text

	switch (logType) {
		default:
		case Info:
			strncpy(type, "[INFO]", 7);
			bgColor = 46; // dark cyan background
			break;
		case Error:
			strncpy(type, "[ERROR]", 8);
			bgColor = 41;
			break;
		case Warning:
			strncpy(type, "[WARNING]", 9);
			bgColor = 43;
			fgColor = 30;
			break;
	}

	va_list argptr;
	va_start(argptr, format);
	vsnprintf(buffer, 255, format.c_str(), argptr);
	va_end(argptr);

	printf("\x1B[%im\x1B[%im%s\x1B[0m (%s - %s:%i): %s\n", bgColor, fgColor, type, file.c_str(), functionName.c_str(), line, buffer);
}