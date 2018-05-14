#ifndef JULKINEN_PELIRAJAPINTA_HH
#define JULKINEN_PELIRAJAPINTA_HH


/**
*	\version $Id: pelirajapinta.hh 2738 2013-04-18 12:04:14Z voutilai $
*	\file pelirajapinta.hh
*	\brief Pelirajapinta-luokan esittely. ($Revision: 2738 $)
*	\author �2011 Eero Salonen <eero.j.salonen@tut.fi>
*
* 	\mainpage
* 	T�m� on  Olio-ohjelmoinnin jatkokurssin vuoden
*      2017 harjoitusty�n Labyrinttipeli valmiina annettu sovelluskehys.
*
* 	Valmiina annetut rajapinnat, tyypit ja luokat l�ytyv�t kaikki
* 	nimiavaruudesta <code>Julkinen</code>.
*/

#include <string>
#include "koordinaatti.h"
#include "luettelotyypit.h"


/// \namespace Julkinen
namespace
	Julkinen
{

	class Nayttorajapinta;

	/**
	*	\class Pelirajapinta
	*	\brief Labyrintti-pelin ohjausrajapinta
	*
	*	T�m�n rajapinnan l�pi pelin p��ohjelma pystyy ohjaamaan pelin toiminta
	*	logiikaa. P��ohjelman vastuulla on pelin alustustiedoston lukeminen ja
	*	komentotulkin py�ritt�minen.
	*
	*	Peli voi olla kahdessa eri tilassa, alustustilassa ja pelitilassa.
	*	Kun peli-olio luodaan se on alustustilassa ja sille voidaan sy�tt��
	*	peliin liittyv�t tiedot, kuten pelialueen koko, pelaajat, palat ja
	*	esineet. Kun peli on alustustilassa ei pelivuoroihin liittyvi�
	*      toiminnalluuksia voida ajaa.
	*
	*	Peli alustetaan kutsumalla ensiksi lisaaNaytto() metodia, jolla peli
	*	liitet��n tulostusrajapintaan. N�yt�n lis�yksen j�lkeen kutsutaan
	*	maaritaPelialueenKoko() metodia, jolla kerrotaan kuinka suuri pelialue
	*	peliss� on. T�m�n j�lkeen peliin lis�t��n palat ja pelaajat kutsumalla
	*	jokaiselle palalle ja pelaajalle lisaaPala tai lisaaPelaaja metodeja.
	*	Kun palat ja pelaajat on lis�tty, niin peliin lis�t��n esineet
	*	kutsumalla lisaaEsine metodia jokaiselle esineelle. Kun alustus on
	*	suoritettu loppuun kutsutaan alustusLopeta metodia.
	*
	*	Peli� pelataan, niin ett� pelaaja vuorollaan ty�nt�� irtopalan
	*	komentoTyonna() metodilla ja t�m�n j�lkeen pelaaja liikkuu
	*	komentoLiiku() metodilla. Poikkeuksena yll� olevaan on tietokone-
	*	pelaaja, joka ei v�ltt�m�tt� ty�nn� palaa vuorollaan vaan k�ytt��
	*	automaatti-liikkumista. Pelaajan vuoron lopuksi kutsutaan
	*	vaihdaVuoro()-metodia.
	*
	*      Poikkeuksista bac_alloc saa vuotaa ulos, jos muisti loppuu. K�yt�nn�ss�
	*      t�m� tarkoittaa sit�, ett� muistin loppumiseen ei v�ltt�m�tt� tarvitse
	*      varautua.
	*
	*      Muistin loppumisesta sek� n�ytt�rajapinnan heitt�mist� poikkeuksista tarjotaan minimitakuu.
	*
	*/
	class Pelirajapinta
	{
	public:


		/**
		*	\brief Oletusrakentaja.
		*
		*  T�m� rakentaja on m��ritelty, jotta voidaan
		*  dokumentoida Pelirajapinnan tila pelin luomisen j�lkeen.
		*
		*  \pre -
		*	\post Peli on alustustilassa ja sen alustaminen voidaan
		*      aloittaa.
		*		Poikkeustakuu: Poikkeuksen sattuessa Pelirajapinta-olion
		*			luonti ep�onnistui, mist� syyt� oliolla ei ole sis�ist�
		*			tilaa jolle voisi antaa takuita.
		*/
		Pelirajapinta()
		{
		}

		/**
		*	\brief Tuhoaja.
		* \pre -
		*	\post No-throw takuu.
		*/
		virtual ~Pelirajapinta()
		{
		}

		/**
		*	\brief Kertoo onko peli alustustilassa.
		* \pre -
		*	\post On palauttanut tiedon onko peli alustustilassa.
		*		Poikkeustakuu: No-throw takuu.
		*
		*	\return Palauttaa <code>true</code> jos peli on alustustilassa.
		*		Palauttaa <code>false</code> jos peli ei ole alustustilassa.
		*/
		virtual bool onkoAlustustilassa() const = 0;

		/**
		*	\brief Lisaa tulostus olion peliin
		*
		*	\pre Peli on alustustilassa. Annettu parametri ei ole tyhj�. N�ytt�� ei ole lis�tty.
		*	\post Tulostus-olio lis�tty peliin.
		*		Poikkeustakuu: No-throw takuu.
		*
		*	\param[in, out] naytto osoitin Nayttorajapinta -luokan
		*	toteuttavaan olioon.
		*/
		virtual void lisaaNaytto(Nayttorajapinta* naytto) = 0;

		/**
		*	\brief Maarittaa pelikent�n koon.
		*
		*	\pre Naytto lisatty peliin.
		*	\post Pelialueen koko on m��ritelty. Perustakuu.
		*
		*	\param[in] koko Julkinen::Koordinaatti joka m��ritt�� pelialueen rajat
		*                      eli kertoo pelialueen oikean alakulman koordinaatin.
		*
		*/
		virtual void maaritaPelialueenKoko(Julkinen::Koordinaatti const& koko) = 0;

		/**
		*	\brief Pelin alustusfunktio, joka lisaa pelaajan peliin
		*
		*	\pre Pelialueen koko on m��ritelty. Peli on alustustilassa.
		*	\post Pelaaja lis�tty peliin.
		*		Poikkeustakuu: Perustakuu poikkeuksen sattuessa.
		*
		*	\param[in] tyyppi Tieto siit� mink�lainen pelaaja lis�t��n.
		*	\param[in] nimi Pelaajan nimi.
		*	\param[in] lyhenne Pelaajaa kuvaava merkki peliss�.
		*	\param[in] sijainti Kertoo mihin labyrintin koordinaattiin pelaaja laitetaan.
		*
		*	\exception Alustusvirhe Annettu koordinaatti on pelialueen ulkopuolella.
		*      \exception Alustusvirhe Annetussa koordinaatissa on jo pelaaja.
		*/
		virtual void lisaaPelaaja(PelaajaTyyppi tyyppi, std::string const& nimi, char lyhenne, Julkinen::Koordinaatti const& sijainti) = 0;

		/**
		*	\brief Pelin alustusfunktio, joka lisaa palan peliin.
		*
		*	\pre Peli on alustustilassa. Pelialueen koko on m��ritelty. Annettuun koordinaattiin ei viel� lis�tty palaa.
		*	\post Pelilautaan on lis�tty pala.
		*		Poikkeustakuu: Perustakuu poikkeuksen sattuessa.
		*
		*	\param[in] pala Tieto siit� mink� laista palaa lis�t��n.
		*	\param[in] rotaatio Lis�tt�v�n palan rotaatio (1-4).
		*				rotaatiota ei tarkasteta jos irtopala
		*	\param[in] sijainti koordinaatti mihin pala lis�t��n.
		*		Jos sijainti.onkoIrtopala() palautaa <code>true</code>,
		*		niin lis�tt�v� pala on irtopala.
		*
		*	\exception Alustusvirhe Annettu koordinaatti on pelialueen ulkopuolella.
		*	\exception Alustusvirhe	Annettu rotaatio on virheellinen.
		*/
		virtual void lisaaPala(PalaTyyppi pala, unsigned int rotaatio, Julkinen::Koordinaatti const& sijainti) = 0;

		/**
		*	\brief Pelin alustusfunktio, joka lisaa esineen peliin.
		*
		*	\pre Peli on alustustilassa. Pelilauta ja pelaajat on alustettu.
		*	\post Esine on lisatty peliin ja mahdollisesti annetulle
		*		pelaajalle, esine on lis�tty ker�tt�viin esineisiin.
		*		Poikkeustakuu: Perustakuu poikkeuksen sattuessa.
		*
		*	\param[in] merkki Esinett� kuvaava merkki peliss�.
		*	\param[in] sijainti Kertoo mihin labyrintin koordinaattiin esine laitetaan.
		*	\param[in] pelaaja Pelaajan nimi jonka teht�v�n� on poimia esine.
		*
		*	\exception Alustusvirhe Pelaajaa ei ole lisatty peliin.
		*	\exception Alustusvirhe Annettu koordinaatti on pelialueen ulkopuolella.
		*/
		virtual void lisaaEsine(char merkki, Julkinen::Koordinaatti const& sijainti, std::string const& pelaaja) = 0;

		/**
		* \brief Pelin alustusfunktio, joka asettaa palan erikoispalan tyypin.
		*
		* \pre Peli on alustustilassa. Pelilauta ja palat on alustettu.
		* \post Palan erikoisominaisuudet on luotu.
		*       Poikkeustakuu: Perustakuu poikkeuksen sattuessa.
		*
		* \param[in] tyyppi Palan erikoistyyppi, joka kertoo onko pala normaali, teleportti, siunattu tai kirottu.
		* \param[in] sijainti Kertoo mit� labyrintin palaa k�sitell��n.
		* \param[in] kohde Teleportti-palan kohderuudun koordinaatti, muilla paloilla parametria ei anneta.
		*
		* \exception Alustusvirhe Annettu koordinaatti on pelialueen ulkopuolella.
		*/
		virtual void asetaPalanTyyppi(Julkinen::ErikoispalaTyyppi tyyppi, Julkinen::Koordinaatti const& sijainti, Julkinen::Koordinaatti const& kohde = Julkinen::Koordinaatti()) = 0;

		/**
		*	\brief Lopettaa pelin alustuksen.
		*
		*	\pre Peli on alustettu.
		*	\post Peli on pelitilassa.
		*		Poikkeustakuu: Perustakuu poikkeuksen sattuessa.
		*/
		virtual void alustusLopeta() = 0;

		/**
		*	\brief Kertoo onko peli pelitilassa.
		* \pre -
		*	\post On palauttanut tiedon onko peli pelitilassa.
		*		Poikkeustakuu: No-throw takuu.
		*
		* 	\return Palauttaa <code>true</code> jos peli on pelitilassa.
		*		Palauttaa <code>false</code> jos peli ei ole pelitilassa.
		*/
		virtual bool onkoPelitilassa() const = 0;

		/**
		*	\brief Ty�nt�� irtopalan annettuun kohtaan.
		*
		*      Raakilepalautuksessa t�t� operaatiota ei kutsuta.
		*
		*	\pre Peli on pelitilassa.
		*	\post Irtopala on asetettu annettuun kohtaan ja ty�nt� kohdan
		*		ty�nt�suunnan mukaisen vastap��n pala on otettu uudeksi
		*		irtopalaksi. Pelilauta on tulostettu uudestaan.
		*		Poikkeustakuu: Vahvatakuu Komentovirhe poikkeuksen sattuessa.
		*
		*
		*	\param[in] reuna Reuna jolle pala ty�nnet��n.
		*	\param[in] rotaatio Ty�nnett�v�n palan rotaatio (1-4)
		*	\param[in] paikka Mihin kohtaan reunaa pala ty�nnet��n.
		*
		*	\exception Toimintovirhe Pelaaja on jo ty�nt�nyt palaa
		*	t�ll� vuorolla.
		*	\exception Komentovirhe Paikka on virheellinen.
		*	\exception Komentovirhe	Rotaatio on virheellinen.
		*/
		virtual void komentoTyonna(Reuna reuna, unsigned int paikka, unsigned int rotaatio) = 0;

		/**
		*	\brief Liikuttaa vuorossa olevaa pelaajaa.
		*
		*	Liikuttaa vuorossa olevaa pelaajaa annettuun suuntaan annetun
		*	m��r�n. Jos pelaaja ei pysty liikkumaan annettuun suuntaan
		*	annettua m��r�� heitet��n Toimintovirhe. Toimintovirhe
		*	heitet��n my�s silloin jos pelaaja ei ole ty�nt�nyt palaa
		*	t�ll� vuorolla, paitsi jos suunta on AUTOMAATTI.
		*      Raakilepalautuksessa liikkuminen suoritetaan, vaikka ty�nt�mist�
		*      ei olekaan suoritettu (eli poikkeusta ei heitet�).
		*
		*
		*
		*	\pre Peli on pelitilassa.
		*	\post Pelaaja on liikutettu ja pelilauta on tulostettu uudestaan.
		*		Poikkeustakuu: Vahvatakuu Komentovirhe tai Toimintovirhe
		*				poikkeuksen sattuessa.
		*
		*	\param[in] suunta Suunta johon pelaajaa siirret��n.
		*	\param[in] maara Pelaajan liikkumien ruutujen m��r�.
		*
		*	\exception Toimintovirhe Vuorossa oleva pelaaja ei voi liikkua
		*		annettuun suuntaan annettua m��r��.
		*	\exception Toimintovirhe Vuorossa oleva pelaaja ei ole
		*		ty�nt�nyt irtopalaa. Ei heitet� jos suunta on AUTOMAATTI.
		*              Ei heitet� raakilepalautuksessa.
		*	\exception Komentovirhe maara on negatiivinen.
		*	\exception Komentovirhe maara on 0, mutta suunta ei ole
		*		PAIKALLAAN.
		*/
		virtual void komentoLiiku(Suunta suunta, unsigned int maara = 0) = 0;

		/**
		*	\brief Vaihtaa vuoron seuraavalle pelaajalle ja ilmoittaa,
		*      jatketaanko peli�, vai onko jokin pelaaja voittanut pelin.
		*      <b>Huom!</b> Raakilepalautuksessa tulkitaan, ett� kukaan ei voita
		*      peli� koskaan (koska ker�tt�vi� esineit� ei ole).
		*
		*	\pre Peli on pelitilassa ja pelaajan toimminnot suoritettu.
		*	\post Peli on loppu tai valmis ottamaan komennon vastaan
		*		vuorossa olevalta pelaajalta.
		*		Poikkeustakuu: Vahvatakuu Toimintovirhe poikkeuksen
		*		sattuessa.
		*
		*	\return <code>false</code>, mik�li peli loppui jonkin
		*      pelaajan voittoon, <code>true</code> jos peli viel�
		*      jatkuu.
		*
		*	\exception Toimintovirhe Pelaajaa ei ole liikkunut
		*		ennen vuoron vaihdon kutsua.
		*/
		virtual bool vaihdaVuoro() = 0;

		/**
		*	\brief Palauttaa vuorossa olevan pelaajan tyypin
		*
		*	\pre Peli on pelitilassa.
		* 	\post Peli on pelitilassa ja vuorossa olevan pelaajan
		*	\c PelaajaTyyppi on palautettu. Poikkeustakuu: No-throw takuu.
		*
		*	\return Palauttaa vuorossa olevan pelaajan <code>PelaajaTyyppi</code>.
		*/
		virtual PelaajaTyyppi haeVuorossa() = 0;

	};
}


#endif //JULKINEN_PELIRAJAPINTA_HH

