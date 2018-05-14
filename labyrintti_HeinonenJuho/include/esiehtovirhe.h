#ifndef JULKINEN_TOT_ESIEHTOVIRHE_HH
#define JULKINEN_TOT_ESIEHTOVIRHE_HH


/**
*  \file esiehtovirhe.hh
*  \brief Julkinen::Esiehtovirhe-luokan esittely.
*  \author �2010 Jarmo Jaakkola <jarmo.jaakkola@tut.fi>,
*      TTY Ohjelmistotekniikka
*/


#include "vaittamavirhe.h" // Kantaluokka.


namespace
	Julkinen
{
	/**
	*	\brief Invariantti assertin l�hett�m�n virhe.
	*/
	class
		Esiehtovirhe
		: public Vaittamavirhe
	{
	public:

		/**
		*	\brief Esiehtovirhe rakentaja.
		*
		*	\param lauseke Merkkijono.
		*	\param tiedosto Merkkijono.
		*	\param rivi Rivinumero.
		*	\param funktio Merkkijono.
		*/
		Esiehtovirhe(
			char const* lauseke,
			char const* tiedosto,
			unsigned int rivi,
			char const* funktio
		)
			throw();

		/**
		*	\brief Purkaja.
		*/
		virtual
			~Esiehtovirhe()
			throw();

		/**
		*	\brief Tulostus virran luonti metodi
		*
		*	\param tuloste Perus tulostevirta.
		*	\return Palauttaa perus tulostevirran.
		*/
		virtual
			std::basic_ostream<char>&
			tulosta(std::basic_ostream<char>& tuloste)
			const;
	};
}


#endif  // JULKINEN_TOT_ESIEHTOVIRHE_HH

