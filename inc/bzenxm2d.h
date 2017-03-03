/**
 * @file:	bzenxm2d.h
 * @brief:	Project Barzensuit XMPP Server Module global settings.
 * 
 * @copyright:	Copyright (C) 2017 Kuhrman Technology Solutions LLC
 * @license:	GPLv3+: GNU GPL version 3
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _BZENXM2D_H_
#define _BZENXM2D_H_

#include <config.h>

/**
 * Activate the XMPP Server on the local host.
 *
 * @return int 0 If the server was started successfully otherwise non-zero.
 */
int start();

/**
 * Terminate the XMPP Server.
 *
 * @return int 0 On a clean shutdown otherwise non-zero.
 */
int stop();

#endif /* _BZENXM2D_H_ */
