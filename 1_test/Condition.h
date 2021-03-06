#pragma once
/* -*-c++-*- OpenThreads library, Copyright (C) 2002 - 2007  The Open Thread Group
*
* This library is open source and may be redistributed and/or modified under
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* OpenSceneGraph Public License for more details.
*/


//
// Condition - C++ condition class
// ~~~~~~~~~
//

#ifndef _OPENTHREADS_CONDITION_
#define _OPENTHREADS_CONDITION_

#include "Exports.h"
#include "Mutex.h"

namespace OpenThreads {

	/**
	*  @class Condition
	*  @brief  This class provides an object-oriented thread condition interface.
	*/
	class OPENTHREAD_EXPORT_DIRECTIVE Condition {

	public:

		/**
		*  Constructor
		*/
		Condition();

		/**
		*  Destructor
		*/
		virtual ~Condition();

		/**
		*  Wait on a mutex.
		*/
		virtual int wait(Mutex *mutex);

		/**
		*  Wait on a mutex for a given amount of time (ms)
		*
		*  @return 0 if normal, -1 if errno set, errno code otherwise.
		*/
		virtual int wait(Mutex *mutex, unsigned long int ms);

		/**
		*  Signal a SINGLE thread to wake if it's waiting.
		*
		*  @return 0 if normal, -1 if errno set, errno code otherwise.
		*/
		virtual int signal();

		/**
		*  Wake all threads waiting on this condition.
		*
		*  @return 0 if normal, -1 if errno set, errno code otherwise.
		*/
		virtual int broadcast();

	private:

		/**
		*  Private copy constructor, to prevent tampering.
		*/
		Condition(const Condition &/*c*/) {};

		/**
		*  Private copy assignment, to prevent tampering.
		*/
		Condition &operator=(const Condition &/*c*/) { return *(this); };

		/**
		*  Implementation-specific data
		*/
		void *_prvData;

	};

}

#endif // !_OPENTHREADS_CONDITION_
