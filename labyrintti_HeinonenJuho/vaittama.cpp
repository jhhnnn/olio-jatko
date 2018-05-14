/**
*  \file vaittama.cc
*  \brief Pysyv�isv�itt�mien tarkistamisen toteutus.
*  \author �2010 Jarmo Jaakkola <jarmo.jaakkola@tut.fi>,
*      TTY Ohjelmistotekniikka
*/


#include "vaittama.h"   // Esittely

#include "include/invarianttivirhe.h"
#include "include/esiehtovirhe.h"
#include "include/jalkiehtovirhe.h"


#include <cassert>


void
Julkinen::vaittamaToteutus(
	VaittamaTyyppi tyyppi,
	bool vaite,
	char const* lauseke,
	char const* tiedosto,
	unsigned int rivi,
	char const* funktio
)
{
	if (!vaite)
	{
		switch (tyyppi)
		{
		case INVARIANTTIVAITTAMA:
		{
			throw Invarianttivirhe(lauseke, tiedosto, rivi, funktio);

		}

		case ESIEHTOVAITTAMA:
		{
			throw Esiehtovirhe(lauseke, tiedosto, rivi, funktio);

		}

		case JALKIEHTOVAITTAMA:
		{
			throw Jalkiehtovirhe(lauseke, tiedosto, rivi, funktio);

		}


		}

		assert(false && "Tuntematon väittämätyyppi!");


	}
}
