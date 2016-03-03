/******************************************************************************
 *
 * package:
 * file:        dailyfileappender.h
 * created:     Jaenner 2015
 * author:      Johann Anhofer
 *
 *
 * Copyright 2007 Martin Heinrich
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/

#ifndef LOG4QT_DAILYFILEAPPENDER_H
#define LOG4QT_DAILYFILEAPPENDER_H

#include "fileappender.h"

#include <QDateTime>
#include <QString>

namespace Log4Qt
{

/*!
 * \brief The class DailyFileAppender extends FileAppender so that the
 * a log file is created for each day
 */
class  LOG4QT_EXPORT DailyFileAppender : public FileAppender
{
    Q_OBJECT

    //! The property holds the date pattern used by the appender.
    Q_PROPERTY(QString datePattern READ datePattern WRITE setDatePattern)
public:
    explicit DailyFileAppender(QObject *pParent = 0);
    DailyFileAppender(LayoutSharedPtr pLayout, const QString &rFileName, const QString &rDatePattern = QString(), QObject *pParent = 0);
    virtual ~DailyFileAppender();

    QString datePattern() const;
    void setDatePattern(const QString &rDatePattern);

    virtual void activateOptions() Q_DECL_OVERRIDE;

    void setLogFileForCurrentDay();

protected:
    virtual void append(const LoggingEvent &rEvent) Q_DECL_OVERRIDE;

#ifndef QT_NO_DEBUG_STREAM
    virtual QDebug debug(QDebug &rDebug) const Q_DECL_OVERRIDE;
#endif // QT_NO_DEBUG_STREAM

private:
    Q_DISABLE_COPY(DailyFileAppender)
    void rollOver();
    QString appendDateToFilename() const;

    QString mDatePattern;
    QDate mLastDate;
    QString mOriginalFilename;
};

}

#endif // LOG4QT_DAILYFILEAPPENDER_H