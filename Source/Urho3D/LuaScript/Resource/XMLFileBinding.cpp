//
// Copyright (c) 2008-2016 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include "../../Precompiled.h"

#include "../../Resource/XMLFile.h"
#include "../../LuaScript/LuaScriptUtils.h"

#include <kaguya.hpp>

namespace Urho3D
{

KAGUYA_MEMBER_FUNCTION_OVERLOADS(XMLFileGetRoot, XMLFile, GetRoot, 0, 1);
KAGUYA_MEMBER_FUNCTION_OVERLOADS(XMLFileToString, XMLFile, ToString, 0, 1);

void RegisterXMLFile(kaguya::State& lua)
{
    using namespace kaguya;

    // [Class] XMLFile : Resource
    lua["XMLFile"].setClass(UserdataMetatable<XMLFile, Resource>()
        // [Constructor] XMLFile()
        .addStaticFunction("new", &CreateObject<XMLFile>)

        // [Method] bool FromString(const String& source)
        .addFunction("FromString", &XMLFile::FromString)
        // [Method] XMLElement CreateRoot(const String& name)
        .addFunction("CreateRoot", &XMLFile::CreateRoot)

        // [Method] XMLElement GetRoot(const String& name = String::EMPTY)
        .addFunction("GetRoot", XMLFileGetRoot())
        // [Method] String ToString(const String& indentation = "\t") const
        .addFunction("ToString", XMLFileToString())

        .addOverloadedFunctions("Patch",
            // [Method] void Patch(XMLFile* patchFile)
            static_cast<void(XMLFile::*)(XMLFile*)>(&XMLFile::Patch),
            // [Method] void Patch(XMLElement patchElement)
            static_cast<void(XMLFile::*)(XMLElement)>(&XMLFile::Patch))
    );
}
}
