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
#include "T2lReport.h"
#include <assert.h>

using namespace T2l;

//=============================================================================
Report::Report(const char* id, int index) :
    id_(id),
    index_(index)
{
}

//=============================================================================
void Report::append(const char* value, ...)
{
    if ( strlen(value) > 1000 ) {
        assert(0);
        return;
    }

    char buffer[10000];
    va_list ap;
    va_start( ap, value );
    vsprintf( buffer, value, ap );
    va_end( ap );

    content_.append(buffer);
}


//=============================================================================
