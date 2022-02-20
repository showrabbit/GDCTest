#pragma once
#include <d3d11.h>

bool CheckHR(HRESULT hr);

#define OBJECT_DISPOSE(o) { if(o != NULL) o->Dispose(); }