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

#include "T2lNaray.h"
#include "T2lInterval.h"
#include <vector>

namespace T2l {

//=============================================================================
template<class T> class Naray3 : public Naray<T, 3> {
//=============================================================================
public:
//<CONSTRUCTION>
    Naray3( int d0, int d1, int d2) : Naray<T, 3>(Ncount<3>({d0, d1, d2})) {}
    virtual ~Naray3() {}
//<METHODS>
    T&     get( int x0, int x1, int x2) { return Naray<T, 3>::get( Tuple<int,3>({x0, x1, x2}) ); }
    void   set( const T& value, int x0, int x1, int x2) { Naray<T, 3>::set(value, T2l::Tuple<int,3>({x0, x1, x2})); }
    int    countX() { return Naray<T, 3>::size_.get(0); }
    int    countY() { return Naray<T, 3>::size_.get(1); }
    int    countZ() { return Naray<T, 3>::size_.get(2); }

    Interval<T> minMax() const;
//=============================================================================
//<OVERRIDES>
//<DATA>
};

template<class T>
Interval<T> Naray3<T>::minMax() const
{
    Interval<T> result;
    for (auto item : Naray<T, 3>::data_) result.inflateTo(item);
    return result;
}

} // namespace T2l
