/** @file */
/*
CS 202 Final Project
Kayleigh Dohm
Drake Lemon
Nicole Siron
*/
#include <iostream>
#include <string>

#include "FileInput.h"
#include "UserInteraction.h"

const int NUM_ARGS = 2;

/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 */

/**
 * Main application entry point.
 *
 * @return
 */
int main(int argc, char const *argv[]) {
	std::string folder = argv[1];
	FileInput::readFiles(folder);

	FileInput monoObj;//object that holds all the info for files
	FileInput stereoObj;		

	UserInteraction::userSelection ;
	
    return 0;

}
