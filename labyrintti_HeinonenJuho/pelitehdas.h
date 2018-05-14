#ifndef JULKINEN_PELITEHDAS_HH
#define JULKINEN_PELITEHDAS_HH
/**
*	\version $Id: pelitehdas.hh 2660 2013-02-15 10:27:37Z bitti $
* 	\file pelitehdas.hh
*	\brief Rajapinta pelin luomiseksi
*	\author ©2010 Eero Salonen <eero.j.salonen@tut.fi>
*
**/

#include "pelirajapinta.h"
#include "peli.h"
#include <memory>

/// \namespace Julkinen
namespace
	Julkinen
{

	/**
	*  \brief Luo instanssi pelirajapinnasta.
	*
	*  P‰‰ohjelma kutsuu t‰t‰ funktiota saadakseen itselleen instanssin
	*  oliosta, joka toteuttaa pelirajapinnan.
	*  Funktion toteutus on teht‰v‰ omaan koodiin.
	*
	*  \post Luodun peli-instanssin tuhoamisvastuu siirtyi p‰‰ohjelmalle.
	*      Luotu olio on alustustilassa.
	*  \return Dynaamisesti luotu instanssi luokasta, joka toteuttaa
	*      Labyrintti-pelin.
	*/
	std::unique_ptr<Pelirajapinta> luoPeli();
}

#endif  // JULKINEN_PELITEHDAS_HH
