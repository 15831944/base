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

#include "T2lNaray2.h"
#include "T2lIntervalF.h"
#include <vector>

namespace T2l {

//=============================================================================
class Naray2f : public Naray2<double> {
//=============================================================================
public:
//<CONSTRUCTION>
    Naray2f( int d0, int d1 ) : Naray2( d0, d1 ) {}
    virtual ~Naray2f() {}
//<METHODS>
    void normalize( const IntervalF& newInterval );
    IntervalF minMax();
//=============================================================================
//<OVERRIDES>
//<DATA>
};

} // namespace T2l
