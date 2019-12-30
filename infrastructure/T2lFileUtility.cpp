//
// Copyright (C) 2019 Petr Talla. [petr.talla@gmail.com]
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//		      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=============================================================================
#include "T2lFileUtility.h"
#include <QDir>

using namespace T2l;

//=============================================================================
QStringList FileUtility::getFilesUp(const QString& dirPath, const QStringList& extensions)
{
    QStringList result;

    QDir dir(dirPath);
    QStringList list = dir.entryList(extensions, QDir::Files);

    for ( int i = 0; i < list.count(); i++ ) {
        result.append(dir.absoluteFilePath(list.at(i)));
    }

    return result;
}

//=============================================================================
