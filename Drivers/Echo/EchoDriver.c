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
#include <Echo/DriverBinding.h>
#include <Protocol/DriverSupportedEfiVersion.h>

GLOBAL_REMOVE_IF_UNREFERENCED
EFI_DRIVER_SUPPORTED_EFI_VERSION_PROTOCOL
gEchoSupportedEfiVersion = {
    sizeof(EFI_DRIVER_SUPPORTED_EFI_VERSION_PROTOCOL),
    EFI_2_60_SYSTEM_TABLE_REVISION
};

EFI_STATUS
EFIAPI
EchoDriverLoad (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
    EFI_STATUS Status = EFI_SUCCESS;

    DEBUG((EFI_D_INFO, "Loading Echo driver\n"));

    gEchoDriverBinding.ImageHandle = ImageHandle;
    gEchoDriverBinding.DriverBindingHandle = ImageHandle;

    Status = gBS->InstallMultipleProtocolInterfaces (
        &ImageHandle,
        &gEfiDriverSupportedEfiVersionProtocolGuid,
        &gEchoSupportedEfiVersion,
        &gEfiDriverBindingProtocolGuid,
        &gEchoDriverBinding,
        &gEfiComponentNameProtocolGuid,
        &gEchoComponentName,
        &gEfiComponentName2ProtocolGuid,
        &gEchoComponentName2,
        NULL
    );

    ASSERT_EFI_ERROR (Status);
    DEBUG((EFI_D_INFO, "Echo driver loaded\n"));
    return Status;
}

EFI_STATUS
EFIAPI
EchoDriverUnload (
    IN EFI_HANDLE ImageHandle
)
{
    EFI_STATUS Status = EFI_SUCCESS;

    DEBUG((EFI_D_INFO, "Unloading Echo driver\n"));

    Status = gBS->UninstallMultipleProtocolInterfaces (
        ImageHandle,
        &gEfiDriverSupportedEfiVersionProtocolGuid,
        &gEchoSupportedEfiVersion,
        &gEfiDriverBindingProtocolGuid,
        &gEchoDriverBinding,
        &gEfiComponentNameProtocolGuid,
        &gEchoComponentName,
        &gEfiComponentName2ProtocolGuid,
        &gEchoComponentName2,
        NULL
    );

    ASSERT_EFI_ERROR (Status);
    DEBUG((EFI_D_INFO, "Echo driver unloaded\n"));
    return Status;
}

/* Echo/EchoDriver.c */

