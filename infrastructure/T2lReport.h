//
// Copyright (C) 2016 Petr Talla. [petr.talla@gmail.com]
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
#pragma once

#include <QString>

namespace T2l
{

//=============================================================================
class Report {
//=============================================================================
public:
//<CONSTRUCTION>
    Report(const char* id, int index = 0);
//<METHOD>
    void clean() { content_ = ""; }
    void append(const char* value, ...);

    const char* id() const { return id_.c_str(); }
    int index() const { return index_; }

    const QString& content() const { return content_; }
//=============================================================================
protected:
//<DATA>
    std::string id_;
    int         index_;
    QString     content_;
};

} //namespace T2l
