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

#include <vector>
#include <sstream>

namespace T2l
{

//=============================================================================
template<class T = double> class Column {
//=============================================================================
public:
//<CONSTRUCTION>
    Column(int size = 0);
    virtual ~Column() {}

//<METHODS>
    T&  get(int index) { return data_.at(index); }
    int count() const { return data_.size(); }
    double sum() const;
    std::string print();
//=============================================================================
//<OVERRIDES>
//<DATA>
    std::vector<T> data_;
};

//=============================================================================
template<class T>
Column<T>::Column(int size) : data_(size, 0)
{
}

//=============================================================================
template<class T>
double Column<T>::sum() const
{
    double result = 0;
    for (int i = 0; i < count(); i++) {
        result += data_.at(i);
    }
    return result;
}

//=============================================================================
template<class T>
std::string Column<T>::print()
{
    std::stringstream ss;
    for ( int i = 0; i < count(); i++ ) {
        if ( i != 0 ) ss << ", ";
        ss << get(i);
    }

    return ss.str();
}

//=============================================================================
typedef Column<double> ColumnF;

} // namespace T2l

//=============================================================================
