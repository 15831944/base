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
#include <T2lColumnF.h>
#include <iostream>

using namespace T2l;
using namespace std;

//=============================================================================
double ColumnF::diffSq(ColumnF& c1, ColumnF& c2)
{
    int count = ColumnF::countCommon(c1, c2);

    double delta = 0;

    for ( int i = 0; i < count; i++ ) {
        double di = c1.get(i) - c2.get(i);
        delta += di*di;
    }

    return delta;
}

//=============================================================================
