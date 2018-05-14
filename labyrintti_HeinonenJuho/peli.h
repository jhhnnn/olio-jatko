#pragma once

#include "pelirajapinta.h"
#include "pelitehdas.h"
#include "include/naytto.h"
#include <memory>
#include <vector>

namespace Julkinen
{
	class peli : public Julkinen::Pelirajapinta
	{
	public:
		peli();
		~peli();

		//pelirajapinnan vaatimat
		virtual bool onkoAlustustilassa()const;
		virtual void lisaaNaytto(Nayttorajapinta* naytto);
		virtual void maaritaPelialueenKoko(Julkinen::Koordinaatti const& koko);
		virtual void lisaaPelaaja(PelaajaTyyppi tyyppi, std::string const& nimi, char lyhenne, Julkinen::Koordinaatti const& sijainti);
		virtual void lisaaPala(PalaTyyppi pala, unsigned int rotaatio, Julkinen::Koordinaatti const& sijainti);
		virtual void lisaaEsine(char merkki, Julkinen::Koordinaatti const& sijainti, std::string const& pelaaja);
		virtual void asetaPalanTyyppi(Julkinen::ErikoispalaTyyppi tyyppi, Julkinen::Koordinaatti const& sijainti, Julkinen::Koordinaatti const& kohde = Julkinen::Koordinaatti());
		virtual void alustusLopeta();
		virtual bool onkoPelitilassa() const;
		virtual void komentoTyonna(Reuna reuna, unsigned int paikka, unsigned int rotaatio);
		virtual void komentoLiiku(Suunta suunta, unsigned int maara = 0);
		virtual bool vaihdaVuoro();
		virtual PelaajaTyyppi haeVuorossa();

	private:
		void tulostaPelaajienTiedot();
		void tulostusSykli();

		struct Esine
		{
			char _esineMerkki = '.';
			Koordinaatti _sijainti;
			bool _loydetty = false;
			std::string _pelaaja;
		};

		struct Pelaaja
		{
			PelaajaTyyppi _tyyppi;
			std::string _nimi;
			char _lyhenne;
			Koordinaatti _sijainti;
			std::vector<Esine> _esineLista;
			std::string _edellinen = "-";
		};

		struct PeliRuutu
		{
			PalaTyyppi _tyyppi;
			unsigned int _rotaatio;
			Koordinaatti _sijainti;
			ErikoispalaTyyppi _erikoisTyyppi = NORMAALI;
			Koordinaatti _kohde;
			std::string _pelaaja;
		};
		

		Nayttorajapinta* _naytto;
		Koordinaatti _koko;
		bool _alustusTila = true;
		bool _voitto = false;
		unsigned int _vuoroNro = 0;
		
		std::vector<PeliRuutu> _pelilauta;
		std::vector<Esine> _esineet;
		std::vector<Pelaaja> _pelaajat;
	};
}
