#ifndef JULKINEN_LOGIIKKAVIRHE_HH
#define JULKINEN_LOGIIKKAVIRHE_HH

#include "virhe.h"

/**
*	\version $Id: koordinaatti.cc 1797 2011-02-03 01:56:31Z salone58 $
*  \file logiikkavirhe.hh
*  \brief Logiikkavirhe-luokan esittely.
*  \author �2010 Eero Salonen <eero.j.salonen@tut.fi>
*/

/// \namespace Julkinen
namespace Julkinen
{
	/**
	*	\class Logiikkavirhe
	*	\brief Virhe toimintalogiikka virhetilanteita varten.
	*/
	class Logiikkavirhe : public Virhe
	{
	public:

		/**
		*  \brief Tunnisteet esim��ritellyille virhetilanteille
		*      k�ytt�j�n antamissa komennoissa.
		*/
		enum
			Virhekoodi
		{
			/**
			*  \brief Tunnistamaton virhe.
			*/
			VIRHE_TUNNISTAMATON
		};

		/**
		*  \brief Tunnistamaton virhetilanne kopioidulla viestill�.
		*
		*  K�yt� t�t� vain, jos kyseess� ei ole mik��n
		*  esim��ritellyist� virheist�.
		*
		*  \copydetails Virhe::Virhe(std::string const&)
		*/
		explicit Logiikkavirhe(std::string const& virheviesti);

		/**
		*  \brief Esim��ritelty virhetilanne.
		*
		*  \post No-throw -takuu.
		*  \param virhekoodi Virhetilanteen tunniste.
		*      Mik�li koodi on VIRHE_TUNNISTAMATON, tulee viestiksi
		*      "Tunnistamaton virhe.".
		*/
		explicit Logiikkavirhe(Virhekoodi virhekoodi);

		/**
		*  \brief Kopiorakentaja.
		*
		*  \post No-throw -takuu.
		*/
		Logiikkavirhe(Logiikkavirhe const& toinen);

		/**
		*  \brief Sijoitusoperaattori.
		*
		*  \post No-throw -takuu.
		*/
		Logiikkavirhe& operator=(Logiikkavirhe const& toinen);

		/**
		*  \brief Sattuneen virhetilanteen virhekoodi.
		*
		*	\return Palauttaa virheen <code>Virhekoodi</code>.
		*/
		Virhekoodi virhe() const;


		/**
		*  \brief Tulosta virheen viesti virtaan.
		*
		*  Tulostaa virheen viestin virtaan, eik� tee muuta.
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
		Virhekoodi virhe_;

	};

}

#endif // JULKINEN_Logiikkavirhe_HH
