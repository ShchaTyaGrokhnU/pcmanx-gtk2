/**
 * Copyright (c) 2005 PCMan <pcman.tw@gmail.com>
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
#include "proxypage.h"
#include "site.h"
#include <stdlib.h>
#include <glib.h>

static void proxy_type_changed(GtkWidget *combo,GtkTable *table);
static string itoa(int);

CProxyPage::CProxyPage(CSite& site) : m_Site(site)
{
  GtkWidget *hbox;
  GtkWidget *auth_info;

  m_Widget = gtk_vbox_new(FALSE,10);
  PostCreate();

  gtk_container_set_border_width (GTK_CONTAINER (m_Widget),30);

  /*--- proxy type ---*/
  hbox = gtk_hbox_new(TRUE,2);
  gtk_box_pack_start(GTK_BOX(m_Widget),hbox,FALSE,FALSE,2); 

  m_ProxyType =  gtk_combo_box_new_text();
  gtk_combo_box_append_text( GTK_COMBO_BOX(m_ProxyType),_("No Proxy"));	
  gtk_combo_box_append_text( GTK_COMBO_BOX(m_ProxyType),"SOCKS4");	
  gtk_combo_box_append_text( GTK_COMBO_BOX(m_ProxyType),"SOCKS5");
  gtk_combo_box_set_active(GTK_COMBO_BOX(m_ProxyType),m_Site.GetProxyType());
  gtk_box_pack_start_defaults(GTK_BOX(hbox),gtk_label_new(_("Proxy Type:")));
  gtk_box_pack_start_defaults(GTK_BOX(hbox),m_ProxyType);

  /*--- detailed proxy info ---*/
  auth_info = gtk_table_new (4,2,TRUE);
  gtk_box_pack_start(GTK_BOX(m_Widget),auth_info,FALSE,FALSE,2);   

  m_ProxyAddr = gtk_entry_new_with_max_length(16);
  m_ProxyPort = gtk_entry_new_with_max_length(6);
  m_ProxyUser = gtk_entry_new();
  m_ProxyPass = gtk_entry_new();

  gtk_table_attach_defaults(GTK_TABLE (auth_info),gtk_label_new(_("IP Address:")),0,1,0,1);
  gtk_table_attach_defaults(GTK_TABLE (auth_info),gtk_label_new(_("Port:")),0,1,1,2);
  gtk_table_attach_defaults(GTK_TABLE (auth_info),gtk_label_new(_("User Name:")),0,1,2,3);
  gtk_table_attach_defaults(GTK_TABLE (auth_info),gtk_label_new(_("Password: ")),0,1,3,4);
  gtk_table_attach_defaults(GTK_TABLE (auth_info),m_ProxyAddr, 1, 2, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE (auth_info),m_ProxyPort, 1, 2, 1, 2);
  gtk_table_attach_defaults(GTK_TABLE (auth_info),m_ProxyUser, 1, 2, 2, 3);
  gtk_table_attach_defaults(GTK_TABLE (auth_info),m_ProxyPass, 1, 2, 3, 4);
  gtk_entry_set_visibility(GTK_ENTRY(m_ProxyPass), false);

  gtk_table_set_row_spacings(GTK_TABLE (auth_info), 5);
  gtk_table_set_col_spacings(GTK_TABLE (auth_info), 5);

  g_signal_connect(G_OBJECT(m_ProxyType),"changed",G_CALLBACK(proxy_type_changed),auth_info);
  
  if(m_Site.GetProxyType()==0)gtk_widget_set_sensitive(GTK_WIDGET(auth_info),FALSE);

  gtk_entry_set_text(GTK_ENTRY(m_ProxyAddr), m_Site.GetProxyAddr().c_str());
  gtk_entry_set_text(GTK_ENTRY(m_ProxyPort), itoa(m_Site.GetProxyPort()).c_str());
  gtk_entry_set_text(GTK_ENTRY(m_ProxyUser), m_Site.GetProxyUser().c_str());
  gtk_entry_set_text(GTK_ENTRY(m_ProxyPass), m_Site.GetProxyPass().c_str());
  gtk_widget_show_all(m_Widget);
}

static void proxy_type_changed(GtkWidget *combo,GtkTable *table)
{
  gint i = gtk_combo_box_get_active(GTK_COMBO_BOX(combo));
  if(i==0)  gtk_widget_set_sensitive(GTK_WIDGET(table),FALSE);
  else gtk_widget_set_sensitive(GTK_WIDGET(table),TRUE);
}

static string itoa(int i)
{
  char buffer[16];
  sprintf(buffer,"%d",i);
  return string(buffer);
}


CProxyPage::~CProxyPage()
{
}


bool CProxyPage::OnOK()
{
  m_Site.SetProxyType(gtk_combo_box_get_active(GTK_COMBO_BOX(m_ProxyType)));
  m_Site.SetProxyAddr(gtk_entry_get_text(GTK_ENTRY(m_ProxyAddr)));
  m_Site.SetProxyPort(atoi(gtk_entry_get_text(GTK_ENTRY(m_ProxyPort))));
  m_Site.SetProxyUser(gtk_entry_get_text(GTK_ENTRY(m_ProxyUser)));
  m_Site.SetProxyPass(gtk_entry_get_text(GTK_ENTRY(m_ProxyPass)));
  return true;
}

