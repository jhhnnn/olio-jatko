#ifndef JULKINEN_NAYTTORAJAPINTA_HH
#define JULKINEN_NAYTTORAJAPINTA_HH

/**
*	\version $Id: nayttorajapinta.hh 2677 2013-02-20 13:03:17Z voutilai $
* 	\file nayttorajapinta.hh
*	\brief Rajapinta pelin luomiseksi ($Revision: 2677 $)
*	\author �2010 Eero Salonen <eero.j.salonen@tut.fi
**/


#include "luettelotyypit.h"
#include "koordinaatti.h"
#include <string>

/// \namespace Julkinen
namespace
	Julkinen
{
	/**
	*	\class Nayttorajapinta
	*	\brief Labyrintti-pelin tulostusrajapinta
	*
	*	Labyrintti pelin toiminnalisuuden toteuttava kirjasto tekee kaikki
	*	tulostukset t�m�n rajapinnan l�pi. Rajapinnan toteutus on p��ohjelman
	*	vastuulla.
	*
	*	Nayttorajapinnan toteutus voi olla kahdessa eri tilassa,
	*	tulostustilassa tai rakennustilassa. Oletuksena n�ytt� on
	*	tulostustilassa, jossa n�ytt� tulostaa ilmoitukset ja tiedot.
	*	Kutsumalla komentoAloitaRakennus() metodia n�ytt� siirtyy
	*	rakennustilaan. Rakennustilassa n�ytt� alkaa odottamaan pelialueen
	*	rakennusta. Pelialue rakennetaan kutsumalla palaLaudalle(),
	*	pelaajaLaudalle() ja esineLaudalle() -metodeja. Rakennus tilassa pit��
	*	kutsua my�s tulostaPelaajantiedot() -metodia jokaiselle pelaajalle.
	*	Pelialueen rakennus lopetetaan kutsumalla komentoLopetaRakennus()
	*	-metodia.
	*
	*	Kaikki ei No-throw metodit heitt�v�t std::bad_alloc poikkeuksen, jos
	*	muisti loppuu. bac_alloc:n yhteydess� luokka tarjoaa minimitakuun.
	*      bad_alloc saa vuotaa ulos, eli muistin loppumiseen ei tarvitse erikseen varautua.
	*/
	class Nayttorajapinta
	{
	public:

		/**
		*  \brief Oletusrakentaja.
		*
		*  T�m� on m��ritelty vain, jotta voitaisiin m��ritell�
		*  olion tila heti luomisen j�lkeen.
		*  \pre -
		*  \post N�ytt�rajapinta on tulostustilassa.
		*		Poikkeustakuu: Poikkeuksen sattuessa Pelirajapinta-olion
		*			luontiep�onnistui, mist� syyt� oliolla ei ole sis�ist�
		*			tilaa jolle voisi antaa takuita
		*/
		Nayttorajapinta() {}

		/**
		*  \brief Oletuspurkaja.
		*  \pre -
		*  \post No-throw -takuu.
		*/
		virtual ~Nayttorajapinta() {}

		/**
		*  \brief Tulostustilan tarkistus.
		*
		*	Kertoo n�yt�n k�ytt�j�lle onko n�ytt� tulostustilassa vai
		*	rakennustilassa.
		* \pre -
		*	\post Palautettu tieto laudan tilasta.
		*		Poikkeusturvallisuus: No-throw takuu.
		*
		*  \return <code>true</code> jos n�ytt� on tulostustilassa,
		*	<code>false</code> jos n�ytt� on rakennustilassa.
		*/
		virtual bool onTulostustilassa() const = 0;
		/**
		*	\brief Tulostaa ilmoituksen esineen poimisesta.
		*
		*	Tulostaa ilmoituksen jossa kerrotaan ett� annettu pelaaja on
		*	poiminut annetun esineen.
		*
		*
		*	\pre N�ytt� tulostustilassa.
		*	\post Ilmoitus esineen poimisesta tehty.
		*		Poikkeusturvallisuus: Vahvatakuu, jos Nayttovirhe.
		*		Muuten perustakuu.
		*
		*	\param[in] esine Poimitun esineen merkki.
		*	\param[in] pelaaja Pelaajan nimi, joka poimi esineen.
		*
		*	\exception Nayttovirhe Tulostus ep�onnistui.
		*/
		virtual void ilmoitusEsinePoimittu(
			char esine,
			std::string const& pelaaja) = 0;

		/**
		* \brief Tulostaa ilmoituksen erikoispalaan astumisesta.
		* Tulostaa ilmoituksen, jossa kerrotaan ett� annettu pelaaja on astunut erikoispalaan, jonka tyyppi on annettu
		*
		* \pre N�ytt� on tulostustilassa.
		* \post Ilmoitus palaan astumisesta tehty.
		* Poikkeusturvallisuus: Vahvatakuu, jos Nayttovirhe.
		* Muuten perustakuu.
		*
		* \param[in] tyyppi Erikoispalan Julkinen:ErikoispalaTyyppi
		* \param[in] pelaaja Pelaajan nimi, joka astui erikoispalaan
		*
		* \exception Nayttovirhe Tulostus ep�onnistui
		*/
		virtual void ilmoitusErikoispalaanAstuttu(Julkinen::ErikoispalaTyyppi tyyppi, std::string const& pelaaja) = 0;
		/**
		*	\brief Tulostaa tiedon vuorossa olevasta pelaajasta.
		*
		*	Tulostaa vuorossa olevan pelaajan nimen ja > merkin sen
		*	j�lkeen. Metodi pit�� ajaa Pelirajapinta::vaihdaVuoro()
		*	-metodi ajon j�lkeen ja aina kun pelaajan antamassa komennossa
		*	on virhe.
		*
		*	\pre N�ytt� tulostustilassa
		*	\post Vuorossa olevan pelaajan nimi tulostettu.
		*		Poikkeustuvallisuus: Vahvatakuu, jos Nayttovirhe.
		*		Muuten perustakuu.
		*
		*	\param[in] nimi Vuorossa olevan pelaajan nimi.
		*
		*	\exception Nayttovirhe Tulostus ep�onnistui.
		*/
		virtual void ilmoitusVuorossa(std::string const& nimi) = 0;

		/**
		*	\brief Lis�� yksitt�isen pelaajan tiedot kartan alle tulostusta varten
		*
		*	\pre N�ytt� on on rakennustilassa. Pelaajan nimen
		*  pituus on <a href="tyoohje.html">ty�ohjeen</a> rajoissa.
		*	\post Pelaajan tiedot on lis�tty tulostettavaksi.
		*		Poikkeusturvallisuus: Perustakuu.
		*
		*	\param[in] nimi Pelaajan, jonka tiedot tulostetaan, nimi.
		*	\param[in] keratytesineet Pelaajan ker��m�t esineet.
		*	\param[in] kerattavatesineet Pelaajan j�ljell� olevat ker�tt�v�t
		*		esineet.
		*	\param[in] edellinentoiminto Pelaajan edellinen toiminto.
		*/
		virtual void tulostaPelaajantiedot(std::string const& nimi,
			std::string const& keratytesineet,
			std::string const& kerattavatesineet,
			std::string const& edellinentoiminto) = 0;

		/**
		*  \brief Laittaa n�yt�n pelialueen rakennustilaan
		*
		*	Asettaa n�yt�n tilan rakennustilaan. T�m� metodi on ajettava
		*	ennen palaLaudalle(), pelaajaLaudalle(), esineLaudalle() ja
		*	komentoLopetaRakennus() metodeja.
		*
		* \pre -
		*  \post N�ytt� on rakennustilassa ja pelilaudan
		*	kuva on tyhj�.
		*	Poikkeusturvallisuus: No-throw takuu.
		*/
		virtual void komentoAloitaRakennus() = 0;

		/**
		*	\brief Lis�� palan tulostettavaan karttaan.
		*
		*	\pre Naytt� on rakennustilassa.
		*		Koordinaatti on pelialueen rajoissa.
		*		Rotaatio on 1-4.
		*	\post Pala on lisatty tulostettavassa bittikartassa annettuun
		*		sijaintiin. Poikkeusturvallisuus: Perustakuu.
		*	\param[in] tyyppi Lis�tt�v�n palan tyyppi.
		* \param[in] etyyppi palaan liitetty Julkinen::ErikoispalaTyyppi, k�ytet��n -n vivun tulostuksen apuna.
		*	\param[in] rotaatio Lis�tt�v�n palan rotaatio.
		*
		*	\param[in] sijainti koordinaatti mihin pala lis�t��n.
		*      Jos sijainti.onkoIrtopala() palautaa <code>true</code>,
		*      niin palasta tehd��n irtopala -kartta.
		*
		* \param[in] kohde Teleporttipalan kohteen koordinaatti. Muilla paloilla parametria ei anneta.
		*
		*/
		virtual void palaLaudalle(Julkinen::PalaTyyppi tyyppi,
			Julkinen::ErikoispalaTyyppi etyyppi, unsigned int rotaatio,
			Julkinen::Koordinaatti const& sijainti, Julkinen::Koordinaatti const& kohde = Julkinen::Koordinaatti()) = 0;

		/**
		*	\brief Lis�� pelaajan merkin tulostettavaan karttaan.
		*
		*	\pre Naytt� on rakennustilassa. Koordinaatti on
		*	pelialueen rajoissa.
		*	\post Pelaaja on lis�tty tulostettavalle kartalle.
		*		Poikkeusturvallisuus: Perustakuu.
		*
		*	\param[in] merkki Pelaajan sijaintia esitt�v� merkki kartalla.
		*	\param[in] sijainti Pelaajan koordinaatti kartalla.
		*
		*/
		virtual void pelaajaLaudalle(char merkki,
			Julkinen::Koordinaatti const& sijainti) = 0;

		/**
		*	\brief Lis�� esineen tulostettavaan lautaan
		*
		*	\pre Naytt� on rakennustilassa. Esineen merkki, jokin
		*	<a href="tyoohje.html">ty�ohjeessa</a> annetuista merkeist�.
		*	Koordinaatti on pelialueen rajoissa.
		*
		*	\post Esine on lis�tty tulostettavalle kartalle.
		*		Poikkeusturvallisuus: Perustakuu.
		*
		*	\param[in] merkki Esine sijaintia esitt�v� merkki kartalla.
		*	\param[in] sijainti Esine koordinaatti kartalla.
		*
		*/
		virtual void esineLaudalle(char merkki,
			Julkinen::Koordinaatti const& sijainti) = 0;

		/**
		*  \brief Lopeta laudanmuodostustila ja tulosta kartta, pelaajien tiedot ja irtopala.
		*
		*  \pre N�ytt� on rakennustilassa.
		*  \post N�ytt�rajapinta on tulostustilassa ja pelilauta on
		*      tulostettu. Poikkeusturvallisuus: Perustakuu.
		*
		*  \exception Nayttovirhe Tulostaminen ep�onnistui.
		*/
		virtual void komentoLopetaRakennus() = 0;
	};


}

#endif // JULKINEN_NAYTTORAJAPINTA_HH

