#ifndef JULKINEN_LUETTELOTYYPIT_HH
#define JULKINEN_LUETTELOTYYPIT_HH

/**
*	\version $Id: pelirajapinta.hh 1844 2011-02-13 22:10:37Z salone58 $
*	\file luettelotyypit.hh
*	\brief Pelirajapinta-luokan esittely. ($Revision: 1844 $)
*	\author �2011 Eero Salonen <eero.j.salonen@tut.fi>
*/

/// \namespace Julkinen
namespace Julkinen
{
	/**
	*	\brief Pelaajan liikumissuunnat
	*/
	enum Suunta
	{
		/**
		*	\brief Pelaaja liikuu alasp�in
		*/
		ALAS,
		/**
		*	\brief Pelaaja liikuu automaattisesti kohti seuraavaa palkintoa
		*
		*	Pelaaja liikkuu ensisijaisesti siihen suuntaan miss� matka
		*	palkintoon on pidempi, jos siihen suuntaan ei voi liikkua,
		*	niin pelaaja liikuu siihen suuntaa, miss� matka palkintoon
		*	on lyhyempi. Jos pelaaja ei pysty liikumaan kumpaankaan
		*	suuntaan, niin pelaaja pysyy paikallaan.
		*
		*	Pelaaja ei ikin� liiku pois p�in palkinnosta, paitsi jos
		*	h�nen poimimansa esineet aiheuttavat moisen siirtym�n.
		*/
		AUTOMAATTI,
		/**
		*	\brief Pelaaja liikuu oikealle
		*/
		OIKEALLE,
		/**
		*	\brief Pelaaja liikuu vasemmalle
		*/
		VASEMMALLE,
		/**
		*	\brief Pelaaja liikuu yl�sp�in
		*/
		YLOS,
		/**
		*	\brief Pelaaja pysyy paikallaan
		*/
		PAIKALLAAN
	};

	/**
	*	\brief Esineiden tyyppitieto
	*/

	//	enum EsineTyyppi
	//	{
	/**
	*	\brief Esine on palkinto esine
	*/
	//		PALKINTO
	/**
	*	\brief Esine on teleportti k��r�
	*/
	//		TELEPORTTI,
	/**
	*	\brief Esine on kirottu poimiva pelaaja menett�� vuoron
	*/
	//		KIROTTU,
	/**
	*	\brief Esine on siunattu pelaaja saa ylim��r�isen vuoron
	*/
	//		SIUNATTU
	//	};

	/**
	*  \brief Erikoispalojen tyyppitieto
	*/
	enum ErikoispalaTyyppi
	{
		/**
		* \brief Pala on normaali, jolla ei ole erikoistoiminnallisuutta.
		*/
		NORMAALI,
		/**
		* \brief Pala on Teleporti
		*/
		TELEPORTTI,
		/**
		* \brief Pala on siunattu, astuva pelaaja saa ylim��r�isen vuoron
		*/
		SIUNATTU,
		/**
		* \brief Pala on kirottu, astuva pelaaja menett�� vuoron
		*/
		KIROTTU
	};

	/**
	*	\brief Tieto millainen pelaaja on kyseess�
	*/
	enum PelaajaTyyppi
	{
		/**
		*	\brief Pelaaja on ihmispelaaja
		*/
		IHMINEN,
		/**
		*	\brief Pelaaja on tietokonepelaaja
		*/
		TIETOKONE

	};

	/**
	*	\brief Tieto siit� mink�muotoinen pala on kyseess�
	*/
	enum PalaTyyppi
	{
		/**
		*	\brief Pala on suorak�yt�v�
		*/
		IPALA,
		/**
		*	\brief Pala on mutka
		*/
		LPALA,
		/**
		*	\brief Pala on T-risteys
		*/
		TPALA
	};

	/**
	*	\brief Tieto mille reunalle irtopala ty�nnettiin
	*/
	enum Reuna
	{
		/**
		*	\brief Pala ty�nnettiin kartan alalaitaan.
		*/
		ALA,
		/**
		*	\brief Pala ty�nnettiin kartan oikeanaanlaitaan.
		*/
		OIKEA,
		/**
		*	\brief Pala ty�nnettiin kartan vasempaan laitaan.
		*/
		VASEN,
		/**
		*	\brief Pala ty�nnettiin kartan yl�laitaan.
		*/
		YLA,
		/**
		*	\brief Pala ty�nnettiin tuntemattomaan paikkaan.
		*/
		EIOLE
	};
}

#endif // JULKINEN_LUETTELOTYYPIT
