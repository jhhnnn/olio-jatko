#ifndef JULKINEN_VAITTAMA_HH
#define JULKINEN_VAITTAMA_HH


/**
*  \file vaittama.hh
*  \brief V�itt�mien tarkistusty�kalujen esittelyt.
*  \author �2010 Jarmo Jaakkola <jarmo.jaakkola@tut.fi>,
*      TTY Ohjelmistotekniikka
*/


namespace
	Julkinen
{
	/**
	*	\brief Luettelotyyppi julkisenrajpinnan assertioille.
	*/
	enum
		VaittamaTyyppi
	{
		INVARIANTTIVAITTAMA,
		ESIEHTOVAITTAMA,
		JALKIEHTOVAITTAMA
	};

	/**
	*  \brief V�itt�mien tarkistamiseen k�ytett�v� funktio.
	*
	*  T�t� funktiota ei ole tarkoitettu kutsuttavaksi suoraan.
	*  K�yt� t�t� ESIEHTO()-, INVARIANTTI()- tai JALKIEHTO()-makron
	*  avulla.
	*
	*  \pre
	\htmlonly
	<var>lauseke</var> &ne; 0 &and; <var>tiedosto</var> &ne; 0
	\endhtmlonly
	*  \post Funktio ei koskaan palaa normaalisti.  Perustakuu poikkeuksen
	*      sattuessa.
	*  \param[in] tyyppi V�itt�m�n tyyppi.
	*  \param[in] vaite Testatun v�itt�m�n totuusarvo.
	*  \param[in] lauseke Testatun v�itt�m�n lauseke merkkijonona.
	*  \param[in] tiedosto Sen tiedoston nimi, jossa v�itt�m� oli.
	*  \param[in] rivi Rivinumero, jolla v�itt�m� oli tiedostossa.
	*  \param[in] funktio Sen funktion nimi, jossa v�itt�m� oli (jos
	*      saatavilla).
	*/
	void
		vaittamaToteutus(
			VaittamaTyyppi tyyppi,
			bool vaite,
			char const* lauseke,
			char const* tiedosto,
			unsigned int rivi,
			char const* funktio
		);
}


#ifdef NDEBUG
/** \brief Varmista luokkainvariantti. */
#  define INVARIANTTI(lauseke)  // Tyhj�.
/** \brief Varmista esiehto. */
#  define ESIEHTO(lauseke)      // Tyhj�.
/** \brief varmista j�lkiehto. */
#  define JALKIEHTO(lauseke)    // Tyhj�.
#else
/**
*  \brief Kutsu vaittamaToteutus()-funktiota sopivin parametrein.
*
*  Ei ole tarkoitettu kutsuttavaksi suoraan.
*/
#  define VAITTAMA(tyyppi, lauseke)                                     \
    Julkinen::vaittamaToteutus(tyyppi, lauseke, #lauseke,               \
            __FILE__, __LINE__, VAITTAMAFUNKTIO)

/**
*  \brief Varmista luokkainvariantti.
*  \pre Lauseke on tosi, ts. jos v�itt�m� ei pid� paikkaansa,
*      mit� vain voi tapahtua, ohjelmas voidaan vaikka kaataa ;-)
*  \param lauseke Tarkistettavan luokkainvariantin lauseke.
*/
#  define INVARIANTTI(lauseke)                                          \
    VAITTAMA(Julkinen::INVARIANTTIVAITTAMA, lauseke)

/**
*  \brief Varmista esiehto.
*  \pre Lauseke on tosi, ts. jos v�itt�m� ei pid� paikkaansa,
*      mit� vain voi tapahtua, ohjelmas voidaan vaikka kaataa ;-)
*  \param lauseke Tarkistettavan esiehdon lauseke.
*/
#  define ESIEHTO(lauseke)                                              \
    VAITTAMA(Julkinen::ESIEHTOVAITTAMA, lauseke)

/**
*  \brief varmista j�lkiehto.
*  \pre Lauseke on tosi, ts. jos v�itt�m� ei pid� paikkaansa,
*      mit� vain voi tapahtua, ohjelmas voidaan vaikka kaataa ;-)
*  \param lauseke Tarkistettavan j�lkiehdon lauseke.
*/
#  define JALKIEHTO(lauseke)                                            \
    VAITTAMA(Julkinen::JALKIEHTOVAITTAMA, lauseke)

// GNU assert.h:ta mukaillen
#  if defined(__GNUG__)
/**
*  \brief GNU-k��nt�j�n hieno funktionimimakro.
*/
#    define VAITTAMAFUNKTIO __PRETTY_FUNCTION__
#  else
/**
*  \brief Funktion nimi ei ole saatavilla t�ll� k��nt�j�ll�.
*/
#    define VAITTAMAFUNKTIO (0)
#  endif

#endif

#endif  // JULKINEN_VAITTAMA_HH
