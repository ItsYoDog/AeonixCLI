/**
  \file      man.h
  \brief     Manpage support.
  \details   This header file is used for manual page support.
  \author    matthyno
  \version   1.0.0
  \date      2021
  \copyright MIT License.
*/

#ifndef __MANPAGE_H
#define __MANPAGE_H

/**
	\brief Initializes the manpages

	Initializes the manual pages.
*/
void manpage_init();

/**
	\brief Gets the manpage of a module.

	Gets the manual page of the module `char* module`. The resulting text is printed to the output.

	\param{in} module The module C file to get the manpage from
*/
char* man(char* module);

#endif