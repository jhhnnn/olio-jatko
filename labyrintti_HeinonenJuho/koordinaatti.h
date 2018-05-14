#ifndef JULKINEN_KOORDINAATTI_HH
#define JULKINEN_KOORDINAATTI_HH


/**
*	\version $Id: koordinaatti.hh 2735 2013-04-18 11:35:51Z bitti $
*  \file koordinaatti.hh
*  \brief Koordinaatti-luokan esittely. ($Revision: 2735 $)
*  \author ©2010 Eero Salonen <eero.j.salonen@tut.fi>
*/

/// \namespace Julkinen
namespace Julkinen
{
	/**
	*	\class Koordinaatti
	*	\brief Luokka pelin sijainti tietojen esitt‰miseen.
	*
	*	Koordinaatti luokka sis‰lt‰‰ X- ja Y-koordinaattin ja tiedon siit‰
	*	ett‰ onko kyseess‰ irtopala.
	*
	*	Koordinaatti -luokasta tehtyyn olioon ei voi sijoittaa uusia arvoja,
	*	muuten kuin toisen koordinaatin sijoittamalla.
	*
	*	Koordinaatti -luokasta tehdyt oliot tarjoavat sis‰lt‰miins‰ arvoihin
	*	hae metodit, mutta arvoihin itseens‰ ei p‰‰se suoraan k‰siksi.
	*/
	class Koordinaatti
	{
	public:

		/**
		*	\brief Rakentaja koordinaattille, jolla annetaan koordinaatin
		*	x ja y sijainnit.
		*
		*	Perusrakentaja koordinaatin k‰ytt‰miseksi.
		*      <b>Huom!</b> T‰st‰ rakentajasta poistettiin x- ja y-koordinaattien
		*      oletusarvot 24.3. (Eli ennen Koordinaatin oletusrakentaja tuotti
		*      tyhm‰sti koordinaatin (0,0), nyt irtopalan.)
		*
		*	\post \c Koordinaatti -olio luotu.
		*
		*	\param [in] xkoord Leveys koordinaatti.
		*	\param [in] ykoord Korkeus koordinaatti.
		*
		*/
		Koordinaatti(unsigned int xkoord, unsigned int ykoord);


		/**
		*	\brief Irtopalan koordinaatin rakentaja ja samalla koordinaatti
		*	-luokan oletusrakentaja.
		*
		*	Tekee koordinaatin jolla pystyt‰‰n tunnistamaan irtopala.
		*      <b>Huom!</b> T‰st‰ rakentajasta tehtiin oletusrakentaja 24.3.
		*      ja <code>bool</code>-parametri poistettiin (koska ainoa j‰rkev‰
		*      rakentajan k‰yttˆ oli parametrilla <code>true</code>).
		*
		*	\post \c Koordinaatti -olio luotu.
		*

		*/
		Koordinaatti();
		/**
		*	\brief Kopiorakentaja.
		*
		*	Kopiorakentaja, jotta koordinaatin kopioiminen onnistuisi.
		*
		*	\post Kopio \c Koordinaatti -oliosta luotu.
		*
		*	\param [in] koordinaatti \c Koordinaatti josta kopio halutaan
		*		tehd‰.
		*/
		Koordinaatti(Koordinaatti const& koordinaatti);

		/**
		*  \brief Tuhoaja.
		*
		*  \post No-throw -takuu.
		*/
		~Koordinaatti();

		/**
		*	\brief Palautaa X-koordinaatin.
		*
		*	\pre Koordinaatti onkoIrtopala on <code>false</code>.
		*	\post palauttaa X-koordinaatin arvon.
		*		Poikkeusturvallisuus: No-throw takuu.
		*
		*	\return palauttaa X-koordinaatin.
		*/
		unsigned int haeXkoordinaatti() const;

		/**
		*	\brief Palautaa Y-koordinaatin.
		*
		*	\pre Koordinaatti onkoIrtopala on <code>false</code>.
		*	\post palauttaa Y-koordinaatin arvon.
		*		Poikkeusturvallisuus: No-throw takuu.
		*
		*	\return palauttaa Y-koordinaatin.
		*/
		unsigned int haeYkoordinaatti() const;

		/**
		*	\brief Kertoo onko kyseess‰ irtopala.
		*
		*	\post palauttaa tiedon siit‰ onko irtopala.
		*		Poikkeusturvallisuus: No-throw takuu.
		*
		*	\return Palauttaa \c true jos kyseess‰ on irtopala.
		*		Palauttaa \c false jos kyseess‰ ei ole irtopala.
		*/
		bool onkoIrtopala() const;

		/**
		*	\brief Sijoitusoperaattori.
		*
		*	Sijoittaa olemassa olevaan koordinaattiin toisen koordinaatin
		*	arvot.
		*
		*	\post Annetun koordinaatin arvot on sijoitettu.
		*		Poikkeusturvallisuus: No-throw takuu.
		*
		*	\param[in] koordinaatti Sijoitettava \c Koordinaatti.
		*/
		void operator=(Koordinaatti const& koordinaatti);

		/**
		*	\brief Yht‰suuruusoperaattori.
		*
		*	Vertaa kohde koordinaatin arvoja omiin arvoihinsa.
		*
		*	\post Palauttanut tiedon siit‰ onko koordinaatit samat.
		*		Poikkeusturvallisuus: No-throw takuu.
		*
		*	\param[in] koordinaatti Verrattava \c Koordinaatti
		*	\return Palauttaa \c true jos arvot yht‰suuret.
		*		Palautaa \c false jos arvot poikkeavat.
		*/
		bool operator==(Koordinaatti const& koordinaatti) const;

		/**
		*      \brief Pienemmyysvertailuoperaattori.
		*
		*      Vertaa kohde koordinaatin arvoja omiin arvoihinsa.
		*
		*      \post Palauttanut tiedon siit‰ onko olio "pienempi" kuin parametri.
		*            Pienemmyydess‰ vertaillaan ensin X- ja sitten Y-koordinaatteja,
		*            ja irtopala on kaikkein pienin.
		(Vertailu tarvitaan, jos Koordinaatteja haluaa k‰ytt‰‰ esim.
		<code>map</code>:n avaimina.)
		*              Poikkeusturvallisuus: No-throw takuu.
		*
		*      \param[in] koordinaatti Verrattava \c Koordinaatti
		*      \return Palauttaa \c true jos olio on "pienempi" kuin parametri.
		*              Palautaa \c false muuten.
		*/
		bool operator<(Koordinaatti const& koordinaatti) const;

	private:

		/// \brief X-koordinaati.
		unsigned int _xkoord;
		/// \brief Y-koordinaatit.
		unsigned int _ykoord;
		/// \brief Onko irtopala.
		bool _irtopala;
	};
}

#endif
