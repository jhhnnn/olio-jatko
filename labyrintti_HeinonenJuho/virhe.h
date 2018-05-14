#ifndef JULKINEN_VIRHE_HH
#define JULKINEN_VIRHE_HH


/**
*	\version $Id: virhe.hh 2660 2013-02-15 10:27:37Z bitti $
*  \file virhe.hh
*  \brief Virhe-luokan esittely.
*  \author �2010 Jarmo Jaakkola <jarmo.jaakkola@tut.fi>,
*      TTY Ohjelmistotekniikka
*/

/*
*	Jos k��nt�j� on GNUG pohjainen esim. gcc tai tutg++ k�ytet��n tr1/memory
*	kirjastoa.
*/
#	if defined(__GNUG__)

#include <tr1/memory>
/*
*	Muussa tapauksessa k�ytet��n memory kirjastoa ja toivotaan ett� k��nt�j�st�
*	l�ytyy alustava tuki uudelle C++ standardille.
*	Toimii esim. Visual Studio 2010.
*/
#	else 
#include <memory>
#	endif

//	STL:n kijastot
#include <iosfwd>       // std::basic_ostream
#include <string>       // std::string
#include <memory>   // std::tr1::shared_ptr

/**
* \brief Nimiavaruus harjoitusty�n valmiina annetulle koodille
*
* Kaikki harjoitusty�n valmiina annettu koodi on nimiavaruudessa
* <code>Julkinen</code>. Ko. nimiavaruuteen ei ole suotavaa laittaa
* omaa koodia.
*/
namespace
	Julkinen
{
	/**
	*	\class Virhe
	*  \brief Labyrintin poikkeusten kantaluokka.
	*
	*  Virheilmoitus voidaan antaa joko std::string-oliona kopioitavaksi,
	*  jolloin olion rakentaminesta voi tulla poikkeus, tai osoittimena
	*  C-merkkijonovakioon, jolloin rakentaminen on no-throw.
	*
	*  Mik�li virheilmoitukseen tarvitsee liitt�� muutakin kuin viesti,
	*  periyt� luokasta uusi tyyppi, jolle tarvittavat tiedot voi antaa
	*  ja uudelleenm��rittele tulosta()-metodi k�ytt�m��n n�it� tietoja.
	*/
	class
		Virhe
	{
	public:

		/**
		*  \brief Kopioidulla viestill�.
		*
		*  \post Perustakuu poikkeuksen sattuessa.
		*  \param virheviesti Merkkijono, joka kopioidaan poikkeuksen
		*      viestiksi.
		*  \exception std::bad_alloc Ei saatu varattua muistia viesti�
		*      varten.
		*/
		explicit
			Virhe(std::string const& virheviesti);

		/**
		*  \brief Muualla tallessa olevalla viestill�.
		*
		*  HUOM!  T�m� luokka \e ei ota vastuuta osoittimen p��ss�
		*  olevan olion tuhoamisesta, eik� tee osoittimen osoittamasta
		*  tiedosta kopiota.  Tarkoituksena on antaa osoitin
		*  esim. k��nn�syksik�n tai luokan sis�iseen
		*  virheviestivakioon, jotta t�m� rakentaja voi tarjota
		*  no-throw -takuun.
		*
		*  \post No-throw -takuu.
		*  \param[in] virheviesti Osoitin oikeaan C-merkkijonovakioon
		*      tai vakioisen <code>std::string</code>-olion
		*      <code>c_str()</code> metodin palauttamaan arvoon.
		*/
		explicit
			Virhe(char const* virheviesti);

		/**
		*  \brief Kopiorakentaja.
		*
		*  \post No-throw -takuu.
		*
		*	\param[in] toinen Kopioitava \c Virhe.
		*/
		Virhe(Virhe const& toinen);

		/**
		*  \brief Purkaja.
		*
		*  \post No-throw -takuu.
		*/
		virtual
			~Virhe();

		/**
		*  \brief Sijoitusoperaattori.
		*
		*  \post No-throw -takuu.
		*
		*	\param[in] toinen Sijoitettava \c Virhe.
		*/
		Virhe&
			operator=(Virhe const& toinen);

		/**
		*  \brief Virheeseen liittyva ilmoitus.
		*
		*  \post No-throw -takuu.
		*/
		char const*
			viesti()
			const;

		/**
		*  \brief Tulosta virheen viesti virtaan.
		*
		*  Tulostaa virheen viestin virtaan, eik� tee muuta.
		*
		*  \post Vahva poikkeustakuu.
		*  \param[in] tuloste Virta, jonne viesti tulostetaan.
		*  \return \p tuloste
		*/
		virtual
			std::basic_ostream<char>&
			tulosta(std::basic_ostream<char>& tuloste)
			const;

	private:

		/**
		*  \brief Kopioitu virheviesti.
		*
		*  Vain toinen muuttujista viestinKopio_ tai viesti_ on
		*  kerrallaan nollasta poikkeava.
		*/
		std::tr1::shared_ptr<char>
			viestinKopio_;

		/**
		*  \brief Muualla sijaitseva virheviesti.
		*
		*  T�m� luokka \e ei ole vastuussa osoittimen p��ss� olevan
		*  luokan tuhoamisesta.
		*
		*  Vain toinen muuttujista viestinKopio_ tai viesti_ on
		*  kerrallaan nollasta poikkeava.
		*/
		char const*
			viesti_;
	};

	/**
	*  \brief Tulosta virhe.
	*
	*  Virhe tulostetaan Virhe::tulosta()-metodilla.
	*
	*  \param[in, out] tuloste Virta jonne tulostetaan.
	*  \param[in] virhe Tulostettava virhe.
	*  \return \p tuloste
	*  \relates Julkinen::Virhe
	*/
	std::basic_ostream<char>&
		operator<<(std::basic_ostream<char>& tuloste, Virhe const& virhe);
}


#endif  // JULKINEN_VIRHE_HH
