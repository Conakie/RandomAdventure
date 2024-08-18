
#include <iostream>
#include "Talk To Encounters English.h"
#include "Parla Con Gli Incontri.h"
#include "Everywhere Used Func.h"
#include "Input.h"



bool lenre(bool sendByElesya)
{
	char answer{ 0 };


	bool answerAgain{ false };



	if (sendByElesya == true)
	{

		std::cout << "(Elesya) LENRE COME HERE!\n(lenre) Che vuoi ELesya?\n(Elesya) Please talk "
			<< "to this human here.\n(Lenre) Ok. Ti piacciono le acciughe?\n"
			<< "A Kelmod no. Dice che si acciugano troppo in fretta.\n"
			<< "Dai dimmi che era una bella battuta.\n\n";
		answer = Input::character();

		if (answer == 'y' || answer == 's')
		{

			std::cout << "Allora c'e' qualcuno a cui piacciono le mie battute.\n"
				<< "Beccatevi questo voi due. Comunque se non lo sapevi credo che Nanre "
				<< "spostera' il nostro ufficio, e forse potremo anche viverci, in una nave.\n"
				<< "E con essa si potra' visitare Asioki. Spero di esserci per le ricette dei dolc"
				<< "i che Nala fara' vedere.\nQuelli dell'anno scorso erano i migliori che ho "
				<< "mangiato nella mia vita.\nNon sto scherzando. Se trovo la ricetta te la do.\n"
				<< "Poi la cerco. Spero che ce ne andremo da qua.\nE' un po' deprimente stare qua"
				<< ".\nOra che ci penso credo che dovremmo ridipingere i muri...\n"
				<< "Vediamo se Kelmod e' libero appena te vai via.\nInteressante...\n"
				<< "Nanre ha detto che non andremo su una nave. Peccato.\nUn'altro avviso?\n"
				<< "Mmmmm non andremo su una nave ma andremo in un'intera crociera visto "
				<< "questo ufficio e le nostre case.\n E avremo un aumento.\n"
				<< "Se non ti dispiace io andrei a festeggiare e a dare la notizia.\n"
				<< "Quindi alla prossima volta che giochi.\n";

		}
		else
		{

			std::cout << "Almeno uno che gli piaccia ci sara'?\n";

		}

	}
	else
	{

		std::cout << "(Lenre) Aspetta un attimo. Come mi hai trovato?.\nNessuno sa dove e' questa "
			<< "stanza.\nComunque se ti piace la modalita' dungeon e la vuoi come scelta all'"
			<< "inizio del gioco chiedi che sia aggiunta.\nIo personalmente preferisco la "
			<< "modalita' mare. Vuoi vederla?\n";

		answer = Input::character();
		if (answer == 'y' || answer == 's')
		{

			system("Color b8");
			std::cout << "\nAllora ti piace? Spero di si visto che ora non puoi cambiarlo.\n"
				<< "A parte gli sfondi trappola che ne dici di darmi una mano a colorare "
				<< "i muri.\nLi devo colorare con 20 colori diversi.\nVoglio sapere chi li ha "
				<< "fatti cosi'. Credo che era un mostro.\nSe non ti dispiace io devo "
				<< "andare a deprimermi in un altro posto.\nAlla prossima volta che non mi vuoi.\n"
				<< "Faccio il bravo e ti rimetto il colore di prima.\nE invece no. Rimarra' "
				<< "cosi'.\n";


		}
		else
		{

			std::cout << "\nAllora vuoi vedere la modalita' oceano?\n";

			answer = Input::character();
			if (answer == 'y' || answer == 's')
			{

				system("Color 37");
				std::cout << "\nNon ti ho detto che poi non potevi tornare indietro...\n"
					<< "Direi che ora e' troppo tardi per cambiarlo.\nVero che non mi ammazzerai?"
					<< "\nDai che devo andare e guardare come e' fatta la nave in cui andremo.\n"
					<< "Da quel che so l'ha fatta la Conakie.\nUna delle migliori produttrici di "
					<< "navi.\nTanto non ti servo. Quindi vado. Alla prossima volta che giochi.\n";

			}
			else
			{

				std::cout << "Non sai cosa hai evitato. Non avevo detto che poi non posso"
					<< " cambiarli.\nNel dubbio lo avevo detto che andremo via da questo ufficio?"
					<< "Credo di si.\nSe non sbaglio la nave dovrebbe avere anche delle stanze per"
					<< " viverci.\nSecondo te quando potremo andarci? Nanre non ha detto quando.\n"
					<< "Quindi potrebbe essere anche domani... Non credo.\n"
					<< "Parlando d'altro sapevi che Kelmod puo' diventare capitano?\n"
					<< "Sono uno dei pochi che sa delle sue lezioni per diventare capitano.\n"
					<< "Spero he ci porti da qualche parte che non sia qua.\n"
					<< "Siamo in guerra da anni ormai. Si nessuno lo ha detto.\nSe vuoi saperne "
					<< "qualcosa in piu' chiedi a Elesya. Lei sa tutto.\nOra io devo andare e "
					<< "preparare i progetti della mia postazione. Quindi ciao.\n\n";

			}

		}

	}


	return false;
}
