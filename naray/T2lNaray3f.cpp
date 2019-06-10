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
#include <T2lNaray3f.h>
#include <iostream>

using namespace T2l;
using namespace std;

//=============================================================================
void Naray3f::normalize( const IntervalF& newInterval )
{
    IntervalF oldInterval = minMax();
    if ( oldInterval.beg() == oldInterval.end() ) return;

    for ( int x = 0; x < countX(); x++ ) {
        for ( int y = 0; y < countY(); y++ ) {
            for ( int z = 0; z < countY(); z++ ) {
                double oldValue = get(x, y, z);
                double newValue = IntervalF::mapValue(oldValue, oldInterval, newInterval);
                set(newValue, x, y, z);

                //cout << oldValue << " >> " << newValue << endl;
            }
        }
    }
}

//=============================================================================
IntervalF Naray3f::minMax()
{
    IntervalF result;

    for ( int x = 0; x < countX(); x++ ) {
        for ( int y = 0; y < countY(); y++ ) {
            for ( int z = 0; z < countY(); z++ ) {
                result.inflateTo( get(x, y, z) );
            }
        }
    }

    return result;
}

//=============================================================================
