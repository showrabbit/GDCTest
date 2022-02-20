#include "Common.h"

bool CheckHR(HRESULT hr)
{
	if (FAILED(hr))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void ReleaseCom()
{

}