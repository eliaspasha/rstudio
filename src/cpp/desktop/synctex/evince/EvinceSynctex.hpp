/*
 * EvinceSynctex.hpp
 *
 * Copyright (C) 2009-12 by RStudio, Inc.
 *
 * This program is licensed to you under the terms of version 3 of the
 * GNU Affero General Public License. This program is distributed WITHOUT
 * ANY EXPRESS OR IMPLIED WARRANTY, INCLUDING THOSE OF NON-INFRINGEMENT,
 * MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE. Please refer to the
 * AGPL (http://www.gnu.org/licenses/agpl-3.0.txt) for more details.
 *
 */

#ifndef DESKTOP_SYNCTEX_EVINCESYNCTEX_HPP
#define DESKTOP_SYNCTEX_EVINCESYNCTEX_HPP

#include <QObject>
#include <QMap>
#include <QPoint>

namespace desktop {

class MainWindow;

namespace synctex {

class EvinceDaemon;
class EvinceWindow;

class EvinceSynctex : public QObject
{
   Q_OBJECT

public:
   explicit EvinceSynctex(MainWindow* pMainWindow);

   void syncView(const QString& pdfFile,
                 const QString& srcFile,
                 const QPoint& srcLoc);

private:
   void syncView(EvinceWindow* pWindow,
                 const QString& srcFile,
                 const QPoint& srcLoc);

private:
   MainWindow* pMainWindow_;
   EvinceDaemon* pEvince_;
   QMap<QString, EvinceWindow*> windows_;
};


} // namespace synctex
} // namespace desktop

#endif // DESKTOP_SYNCTEX_EVINCESYNCTEX_HPP
