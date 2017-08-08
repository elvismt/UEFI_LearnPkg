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

#include <Echo/DriverBinding.h>

EFI_STATUS
EFIAPI
EchoDriverBindingSupported (
    IN  EFI_DRIVER_BINDING_PROTOCOL *This,
    IN  EFI_HANDLE ControllerHandle,
    IN  EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL
)
{
    return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
EchoDriverBindingStart (
    IN  EFI_DRIVER_BINDING_PROTOCOL *This,
    IN  EFI_HANDLE ControllerHandle,
    IN  EFI_DEVICE_PATH_PROTOCOL *RemainingDevicePath OPTIONAL
)
{
    return EFI_UNSUPPORTED;
}

EFI_STATUS
EFIAPI
EchoDriverBindingStop (
    IN EFI_DRIVER_BINDING_PROTOCOL *This,
    IN EFI_HANDLE ControllerHandle,
    IN UINTN NumberOfChildren,
    IN EFI_HANDLE *ChildHandleBuffer OPTIONAL
)
{
    return EFI_UNSUPPORTED;
}

EFI_DRIVER_BINDING_PROTOCOL
gEchoDriverBinding = {
    EchoDriverBindingSupported,
    EchoDriverBindingStart,
    EchoDriverBindingStop,
    ECHO_DRIVER_VERSION,
    NULL,
    NULL,
};

/* Echo/DriverBinding.c */

