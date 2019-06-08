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
#include "T2lGraphics.h"

using namespace T2l;
using namespace std;

//=============================================================================
Graphics::Graphics()
{
}

//=============================================================================
void Graphics::addPoint(double x, double y)
{
    points_.push_back(pair<double, double>(x, y));
}

//=============================================================================
std::pair<double, double> Graphics::getPoint(int index)
{
    if (index < 0) return pair<double, double>(0, 0);
    if (index >= points_.size()) return pair<double, double>(0, 0);

    return points_[index];
}

//=============================================================================
