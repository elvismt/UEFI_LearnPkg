/*
 * Copyright 2017 Elvis M. Teixeira
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to  deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include <Echo/ComponentName.h>

EFI_STATUS
EFIAPI
EchoComponentNameGetDriverName (
    IN  EFI_COMPONENT_NAME2_PROTOCOL *This,
    IN  CHAR8 *Language,
    OUT CHAR16 **DriverName
)
{
    *DriverName = L"EchoDriver";
    return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
EchoComponentNameGetControllerName (
    IN  EFI_COMPONENT_NAME2_PROTOCOL *This,
    IN  EFI_HANDLE ControllerHandle,
    IN  EFI_HANDLE ChildHandle OPTIONAL,
    IN  CHAR8 *Language,
    OUT CHAR16 **ControllerName
)
{
    *ControllerName = L"EchoController";
    return EFI_SUCCESS;
}

GLOBAL_REMOVE_IF_UNREFERENCED
EFI_COMPONENT_NAME_PROTOCOL
gEchoComponentName = {
    (EFI_COMPONENT_NAME_GET_DRIVER_NAME) EchoComponentNameGetDriverName,
    (EFI_COMPONENT_NAME_GET_CONTROLLER_NAME) EchoComponentNameGetControllerName,
    "eng"
};

GLOBAL_REMOVE_IF_UNREFERENCED
EFI_COMPONENT_NAME2_PROTOCOL
gEchoComponentName2 = {
    EchoComponentNameGetDriverName,
    EchoComponentNameGetControllerName,
    "en"
};

/* ComponentName.c */

