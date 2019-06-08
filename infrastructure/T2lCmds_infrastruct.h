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

#include "TcCmdEngine.h"

class TcArgCol;

namespace T2l
{

//=============================================================================
class Cmds_infrastruct {
//=============================================================================
public:
    CMD_FCE( cmd_infrastruct_enum_scripts );
    CMD_FCE( cmd_infrastruct_run_script   );
    CMD_FCE( cmd_infrastruct_report       );

    static bool registerCmds_()
    {
        REGISTER_CMD( "infrastruct_enum_scripts", cmd_infrastruct_enum_scripts, "infrastruct");
        REGISTER_CMD( "infrastruct_run_script",   cmd_infrastruct_run_script,   "infrastruct");
        REGISTER_CMD( "infrastruct_report",       cmd_infrastruct_report,       "infrastruct");

        return true;
    }

    Cmds_infrastruct() = delete;
};

} // namespace T2l
