/**
 * Copyright (c) 2005 PCMan <darren.hoo@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation, 
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef PROXYPAGE_H
#define PROXYPAGE_H

#include "widget.h"
#include <glib/gi18n.h>

class CSite;

/**
 * CProxyPage
 */
class CProxyPage : public CWidget
{
public:
    CProxyPage(CSite& site);

    ~CProxyPage();
    bool OnOK();

	GtkWidget *ProxyPage;	
	GtkWidget *m_ProxyType;
	GtkWidget *m_ProxyAddr;
	GtkWidget *m_ProxyPort;
	GtkWidget *m_ProxyUser;
	GtkWidget *m_ProxyPass;

	CSite& m_Site;
};

#endif


