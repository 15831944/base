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
#include "T2lCmds_infrastruct.h"
#include "TcArgCol.h"
#include "TcArgVal.h"
#include "Protocol.h"
#include "T2lScript.h"
#include "T2lReportSys.h"

#include <string>
#include <sstream>
#include <QString>

using namespace T2l;
using namespace std;

//=============================================================================
int Cmds_infrastruct::cmd_infrastruct_enum_scripts(TcCmdContext* engine, TcArgCol& args)
{
    args.appendVal("<div>script 1</div><div>script 2</div><div>script 2</div>", "result");
    return 1;
}

//=============================================================================
int Cmds_infrastruct::cmd_infrastruct_run_script(TcCmdContext* engine, TcArgCol& args)
{
    if (args.count() < 3) {
        return args.appendError("command expects two arguments, first is directory, second is script name");
    }

    string val1(args.at(1)->getAsVal()->value());
    string val2(args.at(2)->getAsVal()->value());

    Script::run(val1.c_str(), val2.c_str());

    QString result;
    result.append("<div>running:");
    result.append(Script::fileName("honey", "gesture"));
    result.append("</div>");

    args.appendVal(result.toStdString().c_str(), "result");
    return 1;
}

//=============================================================================
int Cmds_infrastruct::cmd_infrastruct_report(TcCmdContext* engine, TcArgCol& args)
{
    stringstream ss;

    if (args.count() == 1) {
        for (int i = 0; i < ReportSys::instance().count(); i++) {
            ss << "<DIV><br>";
            Report* rep = ReportSys::instance().get(i);
            ss << "<b>" << rep->id() << "</b>[" << rep->index() << "]";
            ss << rep->content().toStdString();
            ss << "</DIV>";
        }
    }
    QString text(ss.str().c_str());
    text = text.left(10000);
    Protocol::protocolCmdGet().append(text.toStdString().c_str());
    return 0;
}

//=============================================================================
