// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#pragma once

#include "../Helper/BaseDialog.h"
#include "../Helper/ResizableDialog.h"
#include "../Helper/DialogSettings.h"
#include "../Helper/FileOperations.h"

class CDestroyFilesDialog;

class CDestroyFilesDialogPersistentSettings : public CDialogSettings
{
public:

	~CDestroyFilesDialogPersistentSettings();

	static CDestroyFilesDialogPersistentSettings &GetInstance();

private:

	friend CDestroyFilesDialog;

	static const TCHAR SETTINGS_KEY[];

	static const TCHAR SETTING_OVERWRITE_METHOD[];

	CDestroyFilesDialogPersistentSettings();

	CDestroyFilesDialogPersistentSettings(const CDestroyFilesDialogPersistentSettings &);
	CDestroyFilesDialogPersistentSettings & operator=(const CDestroyFilesDialogPersistentSettings &);

	void SaveExtraRegistrySettings(HKEY hKey);
	void LoadExtraRegistrySettings(HKEY hKey);

	void SaveExtraXMLSettings(IXMLDOMDocument *pXMLDom, IXMLDOMElement *pParentNode);
	void LoadExtraXMLSettings(BSTR bstrName, BSTR bstrValue);

	NFileOperations::OverwriteMethod_t	m_uOverwriteMethod;
};

class CDestroyFilesDialog : public CBaseDialog
{
public:

	CDestroyFilesDialog(HINSTANCE hInstance,int iResource,HWND hParent,std::list<std::wstring> FullFilenameList,BOOL bShowFriendlyDates);
	~CDestroyFilesDialog();

protected:

	INT_PTR	OnInitDialog();
	INT_PTR	OnCtlColorStatic(HWND hwnd,HDC hdc);
	INT_PTR	OnCommand(WPARAM wParam,LPARAM lParam);
	INT_PTR	OnClose();
	INT_PTR	OnDestroy();

private:

	void	GetResizableControlInformation(CBaseDialog::DialogSizeConstraint &dsc, std::list<CResizableDialog::Control_t> &ControlList);
	void	SaveState();

	void	OnOk();
	void	OnCancel();
	void	OnConfirmDestroy();

	std::list<std::wstring>	m_FullFilenameList;

	HICON	m_hDialogIcon;

	CDestroyFilesDialogPersistentSettings	*m_pdfdps;

	BOOL	m_bShowFriendlyDates;
};