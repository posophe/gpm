/*
 * general purpose mouse (gpm)
 *
 * Copyright (c) 2008        Nico Schottelius <nico-gpm2008 at schottelius.org>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 *
 ********/

#include <unistd.h>     /* unlink,geteuid */

#include "headers/message.h"        /* messaging in gpm */
#include "headers/daemon.h"         /* daemon internals */

/* what todo atexit */
void gpm_exited(void)
{
   gpm_report(GPM_PR_DEBUG,GPM_MESS_REMOVE_FILES, GPM_NODE_PID, GPM_NODE_CTL);
   unlink(GPM_NODE_PID);
   unlink(GPM_NODE_CTL);
}

