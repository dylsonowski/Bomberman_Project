#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Bomb.h"
#include <vector>
#include "Animation.h"

//! Klasa abstrakcyjna reprezentujaca klas� graczy.
class PlayableCharacter
{
	public:
		/*! Wirtualny destruktor */
		virtual ~PlayableCharacter() {}

		/*! Klasa czysto wirtualna odpowiadaj�ca za rysowanie obiekt�w na ekranie. */
		virtual void drawPlayer() = 0;

		/*!
			Klasa czysto wirtualna potrzeban do obs�ugi kolozji gracza z blokami. Przesuwa ona gracza w wyznaczonym kierunku.
			\param speedX wartosc o jaka nalezy przesun�� gracza w osi x.
			\param speedX wartosc o jaka nalezy przesun�� gracza w osi y.
		*/
		virtual void playerBumpOff(float speedX, float speedY) = 0;

		/*!
			Metoda czysto wirtualna odpowiadajaco za poruszanie sie gracza oraz odgrywanie odpowiednich klatek animacji w zalezno�ci od kierunku w kt�rym gracz sie porusza.
			\param dt liczba zmiennoprzecinkowa wykorzystywana w obliczeniach do uzyskania p�ynnego ruchu.
		*/
		virtual void playerMovment(float dt) = 0;

		/*! Metoda czysto wirtualna pozwalajaca graczowi na stawianie bomb. Przydziela takze warto�� wska�nikowi "_itsMine" aby kolizja gracza z bomb� by�a rozpatrywana dopiero kiedy gracz z nije zejdzie. */
		virtual void spowningBombs() = 0;

		/*! Metoda czysto wirtualna usuwaj�ca bomb� z kontenera po jej wybuchu. */
		virtual void explodingBomb() = 0;

		/*! Metoda czysto wirtualna zmieniaj�ca flag� "_godMode" na warto�� "false" po up�ywie 5 sekund. */
		virtual void playerUpdate() = 0;

		/*!
			Metoda czysto wirtualna typu "Setter" zmieniajaca flag� "_godMode".
			\param status warto�� boolowa jak� ma przyjac flaga.
		*/
		virtual void setPlayerStatus(bool status) = 0;

		/*!
			Metoda czysto wirtualna typu "Setter" kt�ra zmienia flag� "_death".
			\param death warto�� boolowa jak� ma przyjac flaga.
		*/
		virtual void setIfPlayerDeath(bool death) = 0;

		/*! Metoda czysto wirtualna kt�ra odgrywa animacj� smierci gracza oraz w odpowiednim czasie zmienia flag� "_switchState" umo�liwiajaca zmian� stanu po odegraniu animacji. */
		virtual void playerDeathAnimation() = 0;

		/*! Metoda czysto wirtualna wywo�ujaca metod� "bombUpdate" dla wszystkich obiekt�w w kontenerze. */
		virtual void bombPlacedUpdate() = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\return sprite gracza po przez referencj�. 
		*/
		virtual const sf::Sprite &getSprite() const = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\param iterator indeks w wektorze kt�rego obiekt chcemy otrzyma�.
			\return sprite bomby na pozycji o przekazanym indeksie.
		*/
		virtual const sf::Sprite &getBombSprite(unsigned short int iterator) const = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\param iterator indeks w wektorze kt�rego obiekt chcemy otrzyma�.
			\return sprite wybuchu bomby na pozycji o przekazanym indeksie.
		*/
		virtual const sf::Sprite &getBombExplosionSprite(unsigned short int iterator) const = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\return warto�� ca�kowit� okre�lajac� kierunek gracza.
		*/
		virtual unsigned short int getPlayerDirection() = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\param iterator indeks w wektorze kt�rego obiekt chcemy otrzyma�.
			\return infrmacj� czy bomba na pozycji o przekazanym indeksie wybuch�a.
		*/
		virtual bool getBombsStatus(unsigned short int iterator) = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\return warto�� ca�kowit� okre�lajac� ile bomb postawi� gracz.
		*/
		virtual unsigned short int getBombCount() = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\return status flagi "_godMode".
		*/
		virtual bool getPlayerStatus() = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\return status flagi "_switchState".
		*/
		virtual bool canSwitchState() = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\param iterator indeks w wektorze kt�rego obiekt chcemy otrzyma�.
			\return wska�nik na bomb� o indeksie podanym w argumencie.
		*/
		virtual Bomb *getBomb(unsigned short int iterator) = 0;

		Bomb *_itsMine = nullptr;  /*!< Wska�nik na postawiona przez gracza bomb�. Domy�lnie przyjmuje warto�� "nullptr". */

	protected:
		GameDataRef _data;
		sf::Sprite _playerSprite;  /*!< Sprite reprezentujacy gracza. */
		sf::Sprite _deathSprite;  /*!< Sprite reprezentujacy gracza po utracie �y�. */
		unsigned short int _playerDirection;  /*<! Liczba okre�lajaca kierunek gracza: 1 - g�ra, 2 - d�, 3 - prawo, 4 - lewo. */
		unsigned short int _bombLimit;  /*!< Liczba okreslajaca limit bomb kt�re moze po�o�y� gracz. */
		unsigned short int _placedBombCount = 0;  /*!< Liczba po�o�onych przez gracza bomb. */
		bool _godMode = false;  /*!< Flaga m�wi�ca czy gracz moze zostac trafiony. */
		bool _death = false;  /*!< Flaga m�wiaca czy gracz zgin��. */
		bool _switchState = false;  /*!< Flaga m�wi�ca czy mozan zmienic stan gry. */
		sf::Clock _clock;
		std::vector<Bomb> _bombs;  /*!< Kontener STLa przechowujacy obiekty klasy "Bomb". Kontener dzia�a na zasadzie tablicy jednowymiarowej. */
		sf::Clock _bombCooldown;  /*!< Zegar odmie�ajacy czas po ktorym gracz b�dzie m�g� postawic kolejna bomb�. */
		std::vector<Animation> _animations;  /*!< KOntener STLa przechowujacy obiekty klasy "Animation". Kontener dzia�a na zasadzie tablicy jednowymiarowej. */
		sf::Clock _deathClock;  /*!< Zegar odmie�ajacy czas do zmiany stanu gry. */
		float _timeBeforeDeath = 0;  /*!< Liczba zmienno przecinkowa przechowujaca warto�� czasu kt�ra up�yn�a do �mierci gracza. */
};

/*!
	\file PlayableCharacter.h
	\file definitions.h
	\brief Zawiera potrzebne sta�e oraz �cie�ki do plik�w.
*/