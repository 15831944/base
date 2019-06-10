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

#include <T2lNcount.h>
#include <vector>

namespace T2l
{

template<class T, int N>
int countFromSize_(const Ncount<N>& size)
{
    int result = 1;
    for (int i = 0; i < N; i++) result *= size.get(i);
    return result;
}

//=============================================================================
template<class T, int N = 2> class Naray {
/**< Discrete 3d function. Definition space is 3d cube beginning at value 0.
 * The definition space values are integers. The value for given [x, y, z] is double.
 */
//=============================================================================
public:
//<CONSTRUCTION>
    Naray( const Ncount<N>& size ); ///< [in] The sizes of definition space in particular dimension.
                                                  ///< Because the definition cube starts at 0, it is maximum value-1 as well.
    //Naray( const Naray& ) = default;
    virtual ~Naray() {}

    //Function3d& operator=( const Function3d& ) = default;
    /*void initialize(                              ///< initializes the function by unique value.
            double value);                        ///< [in] the value used for initialization*/
//<METHODS>
    /*double& getData(                              ///< @Returns reference to memory space used for storing partial coordinate [x,y,z]
                                                  ///< !!! There is no check for returnin memory space over the alocated space.
            const T2l::Tuple<int, 3>& xyz);       ///< [in] the coordinate for which is the memory position calculated.*/
    T& get(                                       ///< @Returns the value for coordinate [x, y, z]
            const Tuple<int, N>& nindex)       ///< [in] the coordinate, for which is the value returned
            { return data_[index(nindex)]; }
    void    set(                                  ///< Sets value for coordinate [xyz]
                                                  ///< !!! There is no check for returnin memory space over the alocated space.
            const T& value,                         ///< [in] The value, which will be set.
            const Tuple<int, N>& nindex )      ///< [in] the coordinate, for which is the value set
            { data_[index(nindex)] = value; }
    /*void    add(                                  ///< Adds value at coordinate [xyz]
            double value,                         ///< [in] The value to be added
            const T2l::Tuple<int, 3>& xyz);       ///< [in] the coordinate, where will be the value added

    double integral();                            ///< @Returns sum of all bins.
    void normalize();                             ///< Sets the value of all bins proportionally.
    void regularize(                              ///< Substracts small value from all bins proportionally to ratio.
                                                  ///< Adds the substracted sum to all values proportionally.
                                                  ///< Avoids problems with zero values, replaces them with small value.
            double ratio);                        ///< Proportion to this value is substracted from each bin.
    void sumWidth(                                ///< Adds in the histogram the other histogram.
            const Function3d& other,              ///< [in] The histogram to be added.
            double otherMultiplier = 1.0);        ///< [in] The other histogram values are multiplied with this value
                                                  ///< before the value is added
    void divideBy(                                ///< Divides the histogram the other histogram.
            const Function3d& other );            ///< [in] The histogram to be used for division.
    void multiplyBy(                              ///< Multiplies the histogram the other histogram.
            const Function3d& other);             ///< [in] The histogram to be used for multiplication.*/
    //int countFromSize(const T2l::Tuple<int, N>& size);
    int index(const T2l::Tuple<int, N>& coord) { return size_.index(coord); }
    Tuple<int, N> coord(int index) const { return size_.coord(index); }
    int count() { return countFromSize_<T, N>(size_); }
    Ncount<N>& size() { return size_; }
//=============================================================================
//<OVERRIDES>
//<DATA>
    Ncount<N>       size_;
    std::vector<T>  data_;
};

template<class T, int N>
Naray<T, N>::Naray( const Ncount<N>& size ) :
    size_(size),
    data_(countFromSize_<T, N>(size))
{
}


} // namespace T2l
