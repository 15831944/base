//
// Copyright (C) 2015 Petr Talla. [petr.talla@gmail.com]
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

#include <QList>

namespace T2l {

//=============================================================================
template <class T>
class List {
//=============================================================================
public:
// <CONSTRUCTION>
    List() {}
    virtual ~List() {}
// <METHODS>
    virtual void add(T* item);
    virtual int count() const { return items_.size(); }
    virtual T* get(int index);
    virtual T* const get2(int index) const;
    virtual T* last();
    virtual void remove( int index) { items_.removeAt(index); }
    virtual void remove( T* item ) { items_.removeOne(item); }
    virtual void clean() { items_.clear(); }
//=============================================================================
protected:
// <DATA>
    QList<T*> items_;
};

template <class T>
void List<T>::add(T* item)
{
    items_.append(item);
}

template <class T>
T* List<T>::get(int index)
{
    if (index < 0) return NULL;
    if (index >= count()) return NULL;
    return items_.at(index);
}

template <class T>
T* const List<T>::get2(int index) const
{
    if (index < 0) return NULL;
    if (index >= count()) return NULL;
    return items_.at(index);
}

template <class T>
T* List<T>::last()
{
    if (count()==0) return NULL;
    return get(count()-1);
}

} // namespace t2l
