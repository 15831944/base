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

#include <T2lTuple.h>

namespace T2l
{

//=============================================================================
template<int N = 2> class Ncount : public Tuple<int, N> {
//=============================================================================
public:
//<CONSTRUCTION>
    Ncount() {}
    Ncount( const std::array<int, N>& values ) : Tuple<int, N>(values) {}
    virtual ~Ncount() {}

//<METHODS>
    int count() { int result = 1; for (int i = 0; i < N; i++) result *= Tuple<int, N>::get(i); return result; }
    Tuple<int, N> coord(int index) const;
    int index(const T2l::Tuple<int, N>& coord) const;
//=============================================================================
//<OVERRIDES>
//<DATA>
};

//=============================================================================
template<int N>
int Ncount<N>::index(const T2l::Tuple<int, N>& coord) const
{
    int result = 0;
    for (int i = 0; i < N; i++) {
        int k = 1;
        for(int j = 0; j < i; j++) {
            int ki = Tuple<int, N>::get(j);
            k = k*ki;
        }
        int xi = coord.get(i);
        result += k*xi;
    }
    return result;
}

//=============================================================================
template<int N>
Tuple<int, N> Ncount<N>::coord(int index) const
{
    Tuple<int, N> result;

    for (int i = N-1; i >= 0; i--) {
        int k = 1;
        for ( int j = 0; j < i; j++ ) {
            k *= Tuple<int, N>::get(j);
        }
        result.set(i, index/k);
        index = index%k;
    }

    return result;
}

//=============================================================================
} // namespace T2l
