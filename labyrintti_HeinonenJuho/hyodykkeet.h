#ifndef JULKINEN_TOT_HYODYKKEET_HH
#define JULKINEN_TOT_HYODYKKEET_HH


/**
*  \file hyodykkeet.hh
*  \brief Apufunktioiden esittelyj�.
*  \author �2010 Jarmo Jaakkola <jarmo.jaakkola@tut.fi>,
*      TTY Ohjelmistotekniikka
*/


#include <cstring>      // std::strncpy
#include <map>          // std::map
#include <sstream>      // std::basic_ostringstream
#include <string>       // std::basic_string
/**
*	Jos k��nt�j� on GNUG pohjainen esim. gcc tai tutg++ k�ytet��n tr1/memory
*	kirjastoa.
*/
#	if defined(__GNUG__)

#include <tr1/memory>
/**
*	Muussa tapauksessa k�ytet��n memory kirjastoa ja toivotaan ett� k��nt�j�st�
*	l�ytyy alustava tuki uudelle C++ standardille.
*	Toimii esim. Visual Studio 2010.
*/
#	else
#include <memory>
#	endif


/**
*  \brief Tuhoaja-funktori taulukoiden s�il�miseen
*      std::tr1::shared_ptr:n p��ss�.
*
*  Rakentaja ja purkaja eiv�t voi heitt�� poikkeuksia, koska niill�
*  ei ole mit��n erikoista teht�v��.
*/
template<typename T>
class
	TaulukonTuhoaja
{
public:
	/**
	*  \brief Tuhoa annettu taulukkoosoitin taulukko-deletell�.
	*/
	void
		operator()(T* p)
		const
	{
		delete[] p;
	}
};

/**
*  \brief Lue merkkijono tyypin T olioon.
*
*  \tparam CharT Merkkijonon sis�lt�mien merkkien tyyppi.
*  \tparam T Luettavan tyypin arvo.
*  \param lahde Merkkijono, josta arvo luetaan.
*  \param kohde Olio, johon muunnettu arvo luetaan.  T�ytyy olla
*      luettavissa std::basic_ostream<char>-oliosta >>-operaattorilla.
*  \return Arvo \c true jos ja vain jos arvon muuntaminen onnistui
*      sen lukeminen kulutti \em koko merkkijonon.
*/
template<typename CharT, typename T>
bool
muunnaMerkkijono(std::basic_string<CharT> const& lahde, T& kohde);

/**
*  \brief Varaa dynaamisesti C-merkkijono ja sijoita siihen
*      merkkijonon arvo.
*
*  \tparam CharT Merkkijonon sis�lt�mien merkkien tyyppi.
*  \param merkkijono Merkkijono, jonka sis�lt� kopioidaan.
*  \return Dynaamisesti varattu C-merkkijono.
*/
template<typename CharT>
std::tr1::shared_ptr<CharT>
cMerkkijonoksi(std::basic_string<CharT> const& merkkijono);

/**
*  \brief Muunna arvo toiseksi std::mapin avulla.
*
*  \tparam T1 Muunnoksen l�ht�tyyppi.
*  \tparam T2 Muunnoksen kohdetyyppi.
*  \param muunnettava Muunnettava arvo.
*  \param muuntaja Muunnos tehd��n t�t� hyv�ksi k�ytt�en.
*  \param tunnistamaton Arvo, jota mapista haetaan, jos \p muunnettava
*      ei sielt� l�ytynyt.
*  \returns Haettua vastaava arvo, jos se l�ytyy.  Jos ei l�ydy, niin
*      tunnistamatonta arvoa vastaava.  Jos sit�k��n ei l�ydy niin,
*      T2().
*/
template<typename T1, typename T2>
T2
muunna(
	T1 muunnettava,
	std::map<T1, T2> const& muuntaja,
	T1 tunnistamaton
);


#include "hyodykkeet.cpp"



#endif  // JULKINEN_TOT_HYODYKKEET_HH
