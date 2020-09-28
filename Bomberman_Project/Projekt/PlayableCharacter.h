#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Bomb.h"
#include <vector>
#include "Animation.h"

//! Klasa abstrakcyjna reprezentujaca klasê graczy.
class PlayableCharacter
{
	public:
		/*! Wirtualny destruktor */
		virtual ~PlayableCharacter() {}

		/*! Klasa czysto wirtualna odpowiadaj¹ca za rysowanie obiektów na ekranie. */
		virtual void drawPlayer() = 0;

		/*!
			Klasa czysto wirtualna potrzeban do obs³ugi kolozji gracza z blokami. Przesuwa ona gracza w wyznaczonym kierunku.
			\param speedX wartosc o jaka nalezy przesun¹æ gracza w osi x.
			\param speedX wartosc o jaka nalezy przesun¹æ gracza w osi y.
		*/
		virtual void playerBumpOff(float speedX, float speedY) = 0;

		/*!
			Metoda czysto wirtualna odpowiadajaco za poruszanie sie gracza oraz odgrywanie odpowiednich klatek animacji w zaleznoœci od kierunku w którym gracz sie porusza.
			\param dt liczba zmiennoprzecinkowa wykorzystywana w obliczeniach do uzyskania p³ynnego ruchu.
		*/
		virtual void playerMovment(float dt) = 0;

		/*! Metoda czysto wirtualna pozwalajaca graczowi na stawianie bomb. Przydziela takze wartoœæ wskaŸnikowi "_itsMine" aby kolizja gracza z bomb¹ by³a rozpatrywana dopiero kiedy gracz z nije zejdzie. */
		virtual void spowningBombs() = 0;

		/*! Metoda czysto wirtualna usuwaj¹ca bombê z kontenera po jej wybuchu. */
		virtual void explodingBomb() = 0;

		/*! Metoda czysto wirtualna zmieniaj¹ca flagê "_godMode" na wartoœæ "false" po up³ywie 5 sekund. */
		virtual void playerUpdate() = 0;

		/*!
			Metoda czysto wirtualna typu "Setter" zmieniajaca flagê "_godMode".
			\param status wartoœæ boolowa jak¹ ma przyjac flaga.
		*/
		virtual void setPlayerStatus(bool status) = 0;

		/*!
			Metoda czysto wirtualna typu "Setter" która zmienia flagê "_death".
			\param death wartoœæ boolowa jak¹ ma przyjac flaga.
		*/
		virtual void setIfPlayerDeath(bool death) = 0;

		/*! Metoda czysto wirtualna która odgrywa animacjê smierci gracza oraz w odpowiednim czasie zmienia flagê "_switchState" umo¿liwiajaca zmianê stanu po odegraniu animacji. */
		virtual void playerDeathAnimation() = 0;

		/*! Metoda czysto wirtualna wywo³ujaca metodê "bombUpdate" dla wszystkich obiektów w kontenerze. */
		virtual void bombPlacedUpdate() = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\return sprite gracza po przez referencjê. 
		*/
		virtual const sf::Sprite &getSprite() const = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\param iterator indeks w wektorze którego obiekt chcemy otrzymaæ.
			\return sprite bomby na pozycji o przekazanym indeksie.
		*/
		virtual const sf::Sprite &getBombSprite(unsigned short int iterator) const = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\param iterator indeks w wektorze którego obiekt chcemy otrzymaæ.
			\return sprite wybuchu bomby na pozycji o przekazanym indeksie.
		*/
		virtual const sf::Sprite &getBombExplosionSprite(unsigned short int iterator) const = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\return wartoœæ ca³kowit¹ okreœlajac¹ kierunek gracza.
		*/
		virtual unsigned short int getPlayerDirection() = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\param iterator indeks w wektorze którego obiekt chcemy otrzymaæ.
			\return infrmacjê czy bomba na pozycji o przekazanym indeksie wybuch³a.
		*/
		virtual bool getBombsStatus(unsigned short int iterator) = 0;

		/*!
			Metoda czysto wirtualna typu "Getter".
			\return wartoœæ ca³kowit¹ okreœlajac¹ ile bomb postawi³ gracz.
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
			\param iterator indeks w wektorze którego obiekt chcemy otrzymaæ.
			\return wskaŸnik na bombê o indeksie podanym w argumencie.
		*/
		virtual Bomb *getBomb(unsigned short int iterator) = 0;

		Bomb *_itsMine = nullptr;  /*!< WskaŸnik na postawiona przez gracza bombê. Domyœlnie przyjmuje wartoœæ "nullptr". */

	protected:
		GameDataRef _data;
		sf::Sprite _playerSprite;  /*!< Sprite reprezentujacy gracza. */
		sf::Sprite _deathSprite;  /*!< Sprite reprezentujacy gracza po utracie ¿yæ. */
		unsigned short int _playerDirection;  /*<! Liczba okreœlajaca kierunek gracza: 1 - góra, 2 - dó³, 3 - prawo, 4 - lewo. */
		unsigned short int _bombLimit;  /*!< Liczba okreslajaca limit bomb które moze po³o¿yæ gracz. */
		unsigned short int _placedBombCount = 0;  /*!< Liczba po³o¿onych przez gracza bomb. */
		bool _godMode = false;  /*!< Flaga mówi¹ca czy gracz moze zostac trafiony. */
		bool _death = false;  /*!< Flaga mówiaca czy gracz zgin¹³. */
		bool _switchState = false;  /*!< Flaga mówi¹ca czy mozan zmienic stan gry. */
		sf::Clock _clock;
		std::vector<Bomb> _bombs;  /*!< Kontener STLa przechowujacy obiekty klasy "Bomb". Kontener dzia³a na zasadzie tablicy jednowymiarowej. */
		sf::Clock _bombCooldown;  /*!< Zegar odmie¿ajacy czas po ktorym gracz bêdzie móg³ postawic kolejna bombê. */
		std::vector<Animation> _animations;  /*!< KOntener STLa przechowujacy obiekty klasy "Animation". Kontener dzia³a na zasadzie tablicy jednowymiarowej. */
		sf::Clock _deathClock;  /*!< Zegar odmie¿ajacy czas do zmiany stanu gry. */
		float _timeBeforeDeath = 0;  /*!< Liczba zmienno przecinkowa przechowujaca wartoœæ czasu która up³ynê³a do œmierci gracza. */
};

/*!
	\file PlayableCharacter.h
	\file definitions.h
	\brief Zawiera potrzebne sta³e oraz œcie¿ki do plików.
*/