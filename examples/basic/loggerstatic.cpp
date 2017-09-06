#include "loggerstatic.h"

#include "log4qt/logger.h"
#include "log4qt/logmanager.h"

LOG4QT_DECLARE_STATIC_LOGGER(logger, LoggerStatic)

LoggerStatic::LoggerStatic()
{
    logger()->trace() << "ctor Debug output";
    logger()->info() << "Log4Qt Version String: " << Log4Qt::LogManager::version();
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
    logger()->info() << "Log4Qt Version Number: " << Log4Qt::LogManager::versionNumber().toString();
#endif
}

LoggerStatic::~LoggerStatic()
{
    logger()->trace() << "dtor Debug output";
}
