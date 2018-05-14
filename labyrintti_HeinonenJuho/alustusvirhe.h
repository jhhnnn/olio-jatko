#ifndef JULKINEN_ALUSTUSVIRHE_HH
#define JULKINEN_ALUSTUSVIRHE_HH


/**
*	\version $Id: alustusvirhe.hh 2660 2013-02-15 10:27:37Z bitti $
*  \file alustusvirhe.hh
*  \brief Alustusvirhe-luokan esittely. ($Revision: 2660 $)
*  \author ©2010 Eero Salonen <eero.j.salonen@tut.fi>
*/

#include "virhe.h"

/// \namespace Julkinen
namespace Julkinen
{
	/**
	*	\class Alustusvirhe
	*	\brief Alustuksessa tapahtuvaa virhett‰ kuvaava poikkeus
	*/
	class Alustusvirhe : public Virhe
	{
	public:

		/**
		*	\enum Virhekoodi
		*  \brief Tunnisteet esim‰‰ritellyille virhetilanteille
		*      k‰ytt‰j‰n antamissa komennoissa.
		*/
		enum
			Virhekoodi
		{
			/**
			*  \brief Irtopala on jo tyˆnnetty t‰ll‰ vuorolla ja
			*		pelaaja yritt‰‰ tyˆnt‰‰ sit‰ uudestaan.
			*/
			VIRHE_PALASSA_ON_JO_ESINE,
			/**
			*	\brief Annettu sijainti on virheellinen.
			*/
			VIRHEELLINEN_SIJAINTI,

			/**
			*	\brief Annettu rotaatio on virheellinen.
			*/
			VIRHEELLINEN_ROTAATIO,

			/**
			*	\var Virhekoodi::VIRHE_ANNETTUA_PELAAJAA_EI_LOYTYNYT
			*  \brief Tunnistamaton komento.
			*/
			VIRHE_ANNETTUA_PELAAJAA_EI_LOYTYNYT,
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
		explicit Alustusvirhe(std::string const& virheviesti);

		/**
		*  \brief Esim‰‰ritelty virhetilanne.
		*
		*  \post No-throw -takuu.
		*  \param virhekoodi Virhetilanteen tunniste.
		*      Mik‰li koodi on VIRHE_TUNNISTAMATON, tulee viestiksi
		*      "Tunnistamaton virhe.".
		*/
		explicit Alustusvirhe(Julkinen::Alustusvirhe::Virhekoodi virhekoodi);

		/**
		*  \brief Kopiorakentaja.
		*
		*  \post No-throw -takuu.
		*/
		Alustusvirhe(Julkinen::Alustusvirhe const& toinen);

		/**
		*  \brief Sijoitusoperaattori.
		*
		*  \post No-throw -takuu.
		*/
		Alustusvirhe& operator=(Julkinen::Alustusvirhe const& toinen);

		/**
		*  \brief Sattuneen virhetilanteen virhekoodi.
		*/
		Virhekoodi virhe() const;


		/**
		*  \brief Tulosta virheen viesti virtaan.
		*
		*  Tulostaa virheen viestin virtaan, eik‰ tee muuta.
		*
		*  \post Vahva poikkeustakuu.
		*  \param tuloste Virta, jonne viesti tulostetaan.
		*  \return \p tuloste
		*/
		virtual
			std::basic_ostream<char>&
			tulosta(std::basic_ostream<char>& tuloste)
			const;

	private:
		/**
		* \brief Sattuneen virhetilanteen virhekoodi.
		*/
		Julkinen::Alustusvirhe::Virhekoodi virhe_;

	};

}
#endif // JULKINEN_ALUSTUSVIRHE_HH
