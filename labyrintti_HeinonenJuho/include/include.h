#ifndef INCLUDE_HH
#define INCLUDE_HH

/**
*	\version $Id: include.hh 1802 2011-02-07 09:17:58Z salone58 $
*	\file include.hh
*	\brief p��ohjelman kirjastojen liitt�mistiedosto
*	\author �2011 Eero Salonen <eero.j.salonen@tut.fi>
*/

//Julkinen rajapinta
#include "../koordinaatti.h"
#include "../pelirajapinta.h"
#include "../nayttorajapinta.h"
#include "../pelitehdas.h"
#include "../vaittama.h"
#include "../alustusvirhe.h"
#include "../komentovirhe.h"
#include "../logiikkavirhe.h"
#include "../toteuttamaton_virhe.h"
#include "../virhe.h"
#include "../debug.h"

//Toteutus
#include "komentotulkki.h"
#include "rakentaja.h"


//STL Kirjastot.
/**
*	Jos k��nt�j� on GNUG pohjainen esim. gcc tai tutg++ k�ytet��n tr1/memory
*	kirjastoa.
*/
#	if defined(__GNUG__)

#include <tr1/memory>
/**
*	Muussa tapauksessa k�ytet��n memory kirjastoa ja toivotaan ett� k��nt�j�st�
*	l�ytyy alustava tuki uudelle C++ standardille.
*	Toimii esim. Visual Studio 2010.
*/
#	else
#include <memory>
#	endif
#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>


#endif //INCLUDE_HH
