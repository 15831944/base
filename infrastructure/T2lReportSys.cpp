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
#include "T2lReportSys.h"

using namespace T2l;
using namespace std;

//=============================================================================
ReportSys::ReportSys()
{
}

//=============================================================================
ReportSys& ReportSys::instance()
{
    static ReportSys* i = NULL;
    if (i == NULL) i = new ReportSys();
    return *i;
}

//=============================================================================
Report* ReportSys::get(const char* id, int index)
{
    string idStr(id);

    for ( Report* report : reports_) {
        if ( idStr != report->id() )  continue;
        if ( index != report->index() ) continue;
        return report;
    }

    Report* result = new Report(id, index);
    reports_.push_back(result);
    return result;
}

//=============================================================================
