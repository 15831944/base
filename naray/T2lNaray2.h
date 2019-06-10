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
template<class T> class Naray2 : public Naray<T, 2> {
//=============================================================================
public:
//<CONSTRUCTION>
    Naray2( int d0, int d1 ) : Naray<T, 2>(Ncount<2>({d0, d1})) {}
    virtual ~Naray2() {}
//<METHODS>
    T&     get( int x0, int x1) { return Naray<T, 2>::get( Tuple<int,2>({x0, x1}) ); }
    void   set( const T& value, int x0, int x1) { Naray<T, 2>::set(value, T2l::Tuple<int,2>({x0, x1})); }
    int    countX() { return Naray<T, 2>::size_.get(0); }
    int    countY() { return Naray<T, 2>::size_.get(1); }

    Interval<T> minMax() const;
//=============================================================================
//<OVERRIDES>
//<DATA>
};

template<class T>
Interval<T> Naray2<T>::minMax() const
{
    Interval<T> result;
    for (auto item : Naray<T, 2>::data_) result.inflateTo(item);
    return result;
}

} // namespace T2l
