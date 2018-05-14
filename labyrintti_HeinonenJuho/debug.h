#ifndef JULKINEN_DEBUG_HH
#define JULKINEN_DEBUG_HH


/**
*  \file debug.hh
*  \brief Debuggauksen apumakro
*  \author ©2011 Matti Rintala <bitti@cs.tut.fi>,
*      TTY Ohjelmistotekniikka
*/


#include <iostream>

extern bool debug_output; // Globaali muuttuja, hyi!

						  /**
						  *  \brief Makro, jolla voi tulostaa debug-tulosteita.
						  *
						  * <b>T‰m‰n makron toteutus on viel‰ kesken!</b>
						  *
						  *  K‰ytet‰‰n seuraavasti:
						  *  \code
						  *      DEBUG_OUTPUT("K‰‰k" << std::endl);
						  *  \endcode
						  *
						  *  \post Jos ohjelma on k‰‰nnetty debug-tilassa, tulostus tulostuu
						  *    ruudulle. Muussa tapauksessa mit‰‰n ei tapahdu.
						  */
#define DEBUG_OUTPUT(stuff) if (debug_output) { std::cerr << stuff ; }

#endif  // JULKINEN_DEBUG_HH
