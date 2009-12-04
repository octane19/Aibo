/*
 *  Player - One Hell of a Robot Server
 *
 *  Copyright (C) 2009 - Jesse Lopez
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 *  more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc., 51
 *  Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef AIBO_DRIVER_H_
#define AIBO_DRIVER_H_


#include <unistd.h>

#include <libplayercore/playercore.h>

#include "aibo_comms.h"

////////////////////////////////////////////////////////////////////////////////
// The class for the driver
class Aibo : public ThreadedDriver
{
  public:
    
    // Constructor; need that
    Aibo(ConfigFile* cf, int section);

    // This method will be invoked on each incoming message
    int ProcessMessage(QueuePointer &resp_queue, player_msghdr * hdr,
				void * data);

  private:

  	// Main function for device thread.
  	virtual void Main();
  	virtual int MainSetup();
    virtual void MainQuit();
	
		// The Aibo object
		aibo_comm_t *aibodev;	
		
		// Device Address for proxies in constructor
		player_devaddr_t position_addr;
		player_devaddr_t ptz_addr;

		// Position2d proxy variables
		player_position2d_cmd_vel_t position_cmd;

		// Ports for communication
		const char *ip;
		int main_com_port;
		int walk_com_port;		// Position2d	
		int head_com_port;		// PTZ

		
};


//Need to create destructor
#endif