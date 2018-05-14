#ifndef JULKINEN_KOMENTOVIRHE_HH
#define JULKINEN_KOMENTOVIRHE_HH


/**
*	\version $Id: komentovirhe.hh 2660 2013-02-15 10:27:37Z bitti $
*  \file komentovirhe.hh
*  \brief Komentovirhe-luokan esittely.
*  \author ©2010 Eero Salonen <eero.j.salonen@tut.fi>
*/

#include "virhe.h" // Kantaluokka.

/// \namespace Julkinen
namespace
	Julkinen
{
	/**
	*	\class Komentovirhe
	*  \brief K‰ytt‰j‰n antamaa pelikomentoa ei saatu suoritettua.
	*
	*  Mik‰li k‰ytt‰j‰n ohjelmalle vuorovaikutteisesti antama komento
	*  on jotenkin virheellinen, heitet‰‰n t‰t‰ tyyppi‰ oleva poikkeus.
	*  Olio alustetaan jollakin esim‰‰ritellyist‰ virhekoodeista
	*  tai pelk‰ll‰ virheviestill‰.
	*  Virhekoodilla alustettaessa virheen viestiksi tulee sopiva
	*  selkokielinen viesti ja virheviestill‰ alustettaessa koodiksi
	*  tulee VIRHE_TUNNISTAMATON.
	*  Virheviestill‰ alustamista tulee k‰ytt‰‰ vain sellaisille
	*  virhetilanteille, joille ei ole esim‰‰ritelty‰ koodia.
	*/
	class
		Komentovirhe
		: public Virhe
	{
	public:

		/**
		*!	\enum Virhekoodi
		*  \brief Tunnisteet esim‰‰ritellyille virhetilanteille
		*      k‰ytt‰j‰n antamissa komennoissa.
		*/
		enum
			Virhekoodi
		{

			/**
			*	\brief Annettua paikkaa ei ole kartalla.
			*/
			VIRHE_OLEMATON_PAIKKA,
			/**
			*	\brief Annettu rotaatio on virheellinen.
			*/
			VIRHE_VIRHEELLINEN_ROTAATIO,
			/**
			*	\var Virhekoodi::VIRHE_TUNNISTAMATON_PARAMETRI
			*  \brief Komennolle annettua parametri‰ ei pystytty
			*		tunnistamaan.
			*/
			VIRHE_TUNNISTAMATON_PARAMETRI,
			/**
			*	\var Virhekoodi::VIRHE_TUNNISTAMATON_KOMENTO
			*  \brief Tunnistamaton komento.
			*/
			VIRHE_TUNNISTAMATON_KOMENTO,
			/**
			*	\var Virhekoodi::VIRHE_LIIKAA_PARAMETREJA
			*  \brief Liikaa parametreja.
			*/
			VIRHE_LIIKAA_PARAMETREJA,
			/**
			*  \brief Tunnistamaton virhe.
			*/
			VIRHE_TUNNISTAMATON
		};

		/**
		*  \brief Tunnistamaton virhetilanne kopioidulla viestill‰.
		*
		*  K‰yt‰ t‰t‰ vain, jos kyseess‰ ei ole mik‰‰n
		*  esim‰‰ritellyist‰ virheist‰.
		*
		*  \copydetails Virhe::Virhe(std::string const&)
		*/
		explicit Komentovirhe(std::string const& virheviesti);

		/**
		*  \brief Esim‰‰ritelty virhetilanne.
		*
		*  \post No-throw -takuu.
		*  \param virhekoodi Virhetilanteen tunniste.
		*      Mik‰li koodi on VIRHE_TUNNISTAMATON, tulee viestiksi
		*      "Tunnistamaton virhe.".
		*/
		explicit Komentovirhe(Virhekoodi virhekoodi);

		/**
		*  \copydoc Virhe::Virhe(Virhe const&);
		*/
		Komentovirhe(Komentovirhe const& toinen);

		/**
		*  \copydoc Virhe::operator=(Virhe const& toinen)
		*/
		Komentovirhe& operator=(Komentovirhe const& toinen);

		/**
		*  \brief Sattuneen virhetilanteen virhekoodi.
		*/
		Virhekoodi virhe() const;

		/**
		*  \brief Tulosta "VIRHE: " ja virhekoodiin liittyv‰ viesti.
		*/
		std::basic_ostream<char>&
			tulosta(std::basic_ostream<char>& tuloste)
			const;

	private:

		/**
		* \brief Sattuneen virhetilanteen virhekoodi.
		*/
		Virhekoodi virhe_;
	};
}


#endif  // JULKINEN_KOMENTOVIRHE_HH
