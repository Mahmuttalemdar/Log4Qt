# uncomment if you want to build a static log4qt library
#DEFINES += LOG4QT_STATIC
# uncomment if you want to log to a database via databaselogger
# QT += sql

LOG4QT_VERSION_MAJOR = 1
LOG4QT_VERSION_MINOR = 5
LOG4QT_VERSION_PATCH = 0

DEFINES += LOG4QT_VERSION_MAJOR=$${LOG4QT_VERSION_MAJOR}
DEFINES += LOG4QT_VERSION_MINOR=$${LOG4QT_VERSION_MINOR}
DEFINES += LOG4QT_VERSION_PATCH=$${LOG4QT_VERSION_PATCH}
DEFINES += LOG4QT_VERSION_STR='\\"$${LOG4QT_VERSION_MAJOR}.$${LOG4QT_VERSION_MINOR}.$${LOG4QT_VERSION_PATCH}\\"'
