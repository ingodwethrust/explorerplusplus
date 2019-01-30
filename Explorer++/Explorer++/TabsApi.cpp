// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#include "stdafx.h"
#include "TabsAPI.h"

Plugins::TabsApi::TabsApi(IExplorerplusplus *pexpp)
{
	m_pexpp = pexpp;
}

Plugins::TabsApi::~TabsApi()
{

}

/* TODO: This function
should return a value.
Probably shouldn't
return a HRESULT though. */
void Plugins::TabsApi::create(std::wstring path)
{
	m_pexpp->BrowseFolder(path.c_str(), SBSP_ABSOLUTE, TRUE, TRUE, FALSE);
}