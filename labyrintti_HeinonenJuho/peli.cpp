#include "peli.h"

using namespace Julkinen;

peli::peli()
{
}


peli::~peli()
{
}

bool Julkinen::peli::onkoAlustustilassa() const
{
	return _alustusTila;
}

void Julkinen::peli::lisaaNaytto(Nayttorajapinta * naytto)
{
	_naytto = naytto;
}

void Julkinen::peli::maaritaPelialueenKoko(Julkinen::Koordinaatti const & koko)
{
	_koko = koko;
}

void Julkinen::peli::lisaaPelaaja(PelaajaTyyppi tyyppi, std::string const & nimi, char lyhenne, Julkinen::Koordinaatti const & sijainti)
{
	Pelaaja temp;
	temp._lyhenne = lyhenne;
	temp._nimi = nimi;
	temp._tyyppi = tyyppi;
	temp._sijainti = sijainti;
	_pelaajat.push_back(temp);
}

void Julkinen::peli::lisaaPala(PalaTyyppi pala, unsigned int rotaatio, Julkinen::Koordinaatti const & sijainti)
{
	PeliRuutu temp;
	temp._rotaatio = rotaatio;
	temp._sijainti = sijainti;
	temp._tyyppi = pala;
	_pelilauta.push_back(temp);
}

void Julkinen::peli::lisaaEsine(char merkki, Julkinen::Koordinaatti const & sijainti, std::string const & pelaaja)
{
	Esine temp;
	temp._esineMerkki = merkki;
	temp._sijainti = sijainti;
	temp._pelaaja = pelaaja;
	for (unsigned int i = 0; i < _pelaajat.size(); i++)
	{
		if (_pelaajat.at(i)._nimi == pelaaja)
		{
			_pelaajat.at(i)._esineLista.push_back(temp);
		}
	}

	_esineet.push_back(temp);
}

void Julkinen::peli::asetaPalanTyyppi(Julkinen::ErikoispalaTyyppi tyyppi, Julkinen::Koordinaatti const & sijainti, Julkinen::Koordinaatti const & kohde)
{
	for (unsigned int i = 0; i < _pelilauta.size(); i++) 
	{
		if(_pelilauta.at(i)._sijainti == sijainti)
		{
			_pelilauta.at(i)._erikoisTyyppi = tyyppi;
			_pelilauta.at(i)._kohde = kohde;
		}
	}
}

void Julkinen::peli::alustusLopeta()
{
	tulostusSykli();
	_naytto->ilmoitusVuorossa(_pelaajat.at(_vuoroNro % 4)._nimi);
	_alustusTila = false;
}

bool Julkinen::peli::onkoPelitilassa() const
{
	return !_alustusTila;
}

void Julkinen::peli::komentoTyonna(Reuna reuna, unsigned int paikka, unsigned int rotaatio)
{
	
	tulostusSykli();
}

void Julkinen::peli::komentoLiiku(Suunta suunta, unsigned int maara)
{
	std::string strSuunta;
	Koordinaatti sijainti;
	int x = _pelaajat.at(_vuoroNro % 4)._sijainti.haeXkoordinaatti(), y = _pelaajat.at(_vuoroNro % 4)._sijainti.haeYkoordinaatti();

	switch (suunta)
	{
	case Julkinen::ALAS:
		strSuunta = "a";
		y = y - maara;
		break;
	case Julkinen::OIKEALLE:
		strSuunta = "o";
		x = x + maara;
		break;
	case Julkinen::VASEMMALLE:
		strSuunta = "v";
		x = x - maara;
		break;
	case Julkinen::YLOS:
		strSuunta = "y";
		y = y + maara;
		break;
	case Julkinen::PAIKALLAAN:
		_pelaajat.at(_vuoroNro % 4)._edellinen = "(paikallaan)";
		break;
	default:
		break;
	}

	sijainti = Koordinaatti(x,y);
	_pelaajat.at(_vuoroNro % 4)._sijainti = sijainti;
	_pelaajat.at(_vuoroNro % 4)._edellinen = "(liiku " + strSuunta + " " + std::to_string(maara) + ")";
	tulostusSykli();
}

bool Julkinen::peli::vaihdaVuoro()
{
	if (_voitto) {
		return false;
	}
	else {
		_vuoroNro++;
	}
	return true;
}

PelaajaTyyppi Julkinen::peli::haeVuorossa()
{
	PelaajaTyyppi tyyppi = _pelaajat.at(_vuoroNro % 4)._tyyppi;
	return tyyppi;
}

void Julkinen::peli::tulostaPelaajienTiedot()
{
	for (unsigned int i = 0; i < _pelaajat.size(); i++)
	{
		std::string etsittavat;
		std::string loydetyt;
		bool eka = true;

		for (unsigned int j = 0; j < _pelaajat.at(i)._esineLista.size(); j++)
		{
			if (_pelaajat.at(i)._esineLista.at(j)._loydetty) 
			{
				loydetyt.push_back(_pelaajat.at(i)._esineLista.at(j)._esineMerkki);
			}
			else {
				if (eka)
				{
					etsittavat.push_back(_pelaajat.at(i)._esineLista.at(j)._esineMerkki);
					eka = false;
				}
				else
				{
					etsittavat.push_back('*');
				}
			}
		}
		
		_naytto->tulostaPelaajantiedot(_pelaajat.at(i)._nimi,loydetyt,etsittavat, _pelaajat.at(i)._edellinen);
	}

	
}

void Julkinen::peli::tulostusSykli()
{
	_naytto->komentoAloitaRakennus();
	for (unsigned int i = 0; i < _pelilauta.size(); i++)
	{
		_naytto->palaLaudalle(_pelilauta.at(i)._tyyppi, _pelilauta.at(i)._erikoisTyyppi, _pelilauta.at(i)._rotaatio, _pelilauta.at(i)._sijainti, _pelilauta.at(i)._kohde);
	}
	for (unsigned int j = 0; j < _esineet.size(); j++)
	{
		_naytto->esineLaudalle(_esineet.at(j)._esineMerkki, _esineet.at(j)._sijainti);
	}
	for (unsigned int k = 0; k < _pelaajat.size(); k++)
	{
		_naytto->pelaajaLaudalle(_pelaajat.at(k)._lyhenne, _pelaajat.at(k)._sijainti);
	}
	tulostaPelaajienTiedot();
	_naytto->komentoLopetaRakennus();
}

std::unique_ptr<Pelirajapinta> Julkinen::luoPeli()
{
	std::unique_ptr<Pelirajapinta> p(new peli());
	return p;
}