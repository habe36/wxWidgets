/////////////////////////////////////////////////////////////////////////////
// Name:        icon.cpp
// Purpose:     wxIcon class
// Author:      Julian Smart
// Modified by:
// Created:     17/09/98
// RCS-ID:      $Id$
// Copyright:   (c) Julian Smart
// Licence:   	wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "icon.h"
#endif

// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#include "wx/icon.h"

IMPLEMENT_DYNAMIC_CLASS(wxIcon, wxBitmap);

// ============================================================================
// Icons
// ============================================================================

wxIcon::wxIcon()
{
}

// Create from XBM data
wxIcon::wxIcon(const char bits[], int width, int height)
{
    (void) Create((void*) bits, wxBITMAP_TYPE_XBM_DATA, width, height, 1);
}

// Create from XPM data
wxIcon::wxIcon(char **data)
{
    (void) Create((void*) data, wxBITMAP_TYPE_XPM_DATA, 0, 0, 0);
}

wxIcon::wxIcon(const char **data)
{
    (void) Create((void*) data, wxBITMAP_TYPE_XPM_DATA, 0, 0, 0);
}

void wxIcon::CopyFromBitmap(const wxBitmap& bmp)
{
    wxIcon *icon = (wxIcon*)(&bmp);
    *this = *icon;
}

wxIcon::~wxIcon()
{
}

bool wxIcon::LoadFile(const wxString& filename, wxBitmapType type,
                      int desiredWidth, int desiredHeight)
{
    UnRef();

    wxBitmapHandler *handler = FindHandler(type);
    
    if ( handler )
        return handler->LoadFile(this, filename, type,
                                 desiredWidth, desiredHeight);
    else
        return FALSE;
}
