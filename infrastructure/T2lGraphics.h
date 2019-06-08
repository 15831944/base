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
#include <utility>

namespace T2l
{

//=============================================================================
class Graphics {
//=============================================================================
public:
//<CONSTRUCTION>
    Graphics();
//<METHOD>
    void addPoint(double x, double y);
    std::pair<double, double> getPoint(int index);
//=============================================================================
protected:
//<DATA>
    std::vector< std::pair<double, double> > points_;
};

} //namespace T2l
