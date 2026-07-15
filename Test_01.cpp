// Test_01.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "QuestSystem.h"
// #include "Delivery.h"
// #include "Escort.h"
// #include "Gather.h"
#include "Kill.h"

// #include <iostream>
/*
//die funcion
void youDied(char& choice)
{
    cout << "You died omegaLUL" << endl;
    cout << "Do you wanna play again?";
    cin >> choice;
    putchar(toupper(choice));

}
//set to begin play
void eventBeginPlay(char& choice)
{

    cout << "Event has begin..." << endl;
    cout << "You woke up in Forest, meet the wolf:'follow me to the field...\nwhat do you do? (Y-follow/N-do not follow): ";
    cin >> choice;
    putchar(toupper(choice));
}
// destoying QS
void destroyerQuestSystem(QuestSystem<void> qs, Gather<void> gath, Escort<void> escanor, Kill<void> kill, Delivery<void> deliv)
{
    qs.~QuestSystem();
    gath.~Gather();
    escanor.~Escort();
    kill.~Kill();
    deliv.~Delivery();
}*/
int main()
{
    // init
    /* bool mainQuest = true;
     bool activeQuest = true;
     char choice = ' ';
     int sumDeath = 1;
     int& slyer = sumDeath;
     bool delivery = false;
     bool& smthDeliver = delivery;
     bool travel = false;
     string typ = "TEST";

     QuestSystem<void> qs = QuestSystem<void>(typ, mainQuest, activeQuest);
     Gather<void> gath;
     Escort<void> escanor;
     Kill<void> kill;
     Delivery<void> deliv;

     eventBeginPlay(choice);

     if (choice == 'Y')
     {
         cout << "Wolf run in front of you. You are come to the field...'Could You collect the rosies? \n";
         cout << "If you do, I will speak at the guard to get audience with the king, then he will fulfill any wish'\nWhat will you do? (Y-Collect rossies/N-go for the walk):";
         cin >> choice;
         putchar(toupper(choice));
         //esord function
         travel = true;
         if (choice == 'Y')
         {
             cout << "You see some rocks and downy crab spider what will you do?(Y-Take a rock and kill the monster/N-Run back to the wolf) ";
             cin >> choice;
             putchar(toupper(choice));
             //kill function delivery function
             if (choice == 'Y')
             {
                 cout << "You kill a monster and you took a gold locket from it" << endl;
                 kill.CompleteSlayer(sumDeath, slyer);
                 cout << "'I see you have rossies and you find princess gold medallion, how brave are you'\nFollow the path and may fortune accompany you..\n";
                 cout << "You came to a dilapidated shack, do you want to sleep? (Y-hell yes/N-nope)";
                 cin >> choice;
                 putchar(toupper(choice));
                 if (choice == 'Y')
                 {
                     cout << "It is a beatiful day and you woke up by heavy pinch in the back....\n";
                     cout << "'Wake up we have to visit king hurry' said knight in shiny armor\n You run with him...\n Guards saluted and knight said, you are with him...\n";
                     cout << "'You have an audience with king' said, now the king come.\nThe knight told him everything you did..." << endl;
                     cout << "The king suddenly he glares at you and knight said:'You have to hand over flowers and locket now'. What will you do? (Y-You do/N-You do not)";
                     cin >> choice;
                     putchar(toupper(choice));
                     if (choice == 'Y')
                     {
                         cout << "'Princess will be pleased'said...\nNow the king awakens you by shaking with you..\n END GAME LULW" << endl;
                         travel = false;
                         deliv.CompleteDelivery(smthDeliver);
                         escanor.TravelEnd(travel, "Home");
                         destroyerQuestSystem(qs, gath, escanor, kill, deliv);
                     }
                     else
                     {
                         youDied(choice);
                         destroyerQuestSystem(qs, gath, escanor, kill, deliv);
                     }
                 }
                 else
                 {
                     youDied(choice);
                     destroyerQuestSystem(qs, gath, escanor, kill, deliv);
                 }
             }
             else
             {
                 youDied(choice);
                 destroyerQuestSystem(qs, gath, escanor, kill, deliv);
             }
         }
         else
         {
             youDied(choice);
             destroyerQuestSystem(qs, gath, escanor, kill, deliv);
         }
     }
     else
     {
         cout << "Wolf come after you and ..." << endl;
         destroyerQuestSystem(qs, gath, escanor, kill, deliv);
         youDied(choice);
     }*/

    // Kompilátor vidí jak deklaraci z .h, tak tělo z .ipp,
    // takže bez problému vygeneruje správný kód pro <void>!

    // Malý testovací výpis, abychom viděli, že program vůbec žije
    std::cout << "--- QUEST SYSTEM START ---" << std::endl;

    int myStats = 0;

    // Vytvoření tvého questu
    // (Předpokládám, že máš opravené konstruktory)
    Kill<void> ratQuest("Zabij 10 krys nebo zammori cely svet", true, true, 10, 0, myStats);
    QuestSystem<void> myQuest = ratQuest;
    myQuest.printQuestStatus();

    // Tady zkus zavolat nějakou metodu, která v sobě má výpis (cout)
    // Např. CompleteSlayer nebo něco podobného, co vypisuje stav.

    std::cout << "\n--- KONEC PROGRAMU ---" << std::endl;

    // Tento řádek donutí konzoli počkat na stisknutí klávesy, než se zavře
    std::cin.get();

    return 0;

    // QuestSystem<void> myQuest("Kill 10 Rats", true, true);
    // myQuest.printQuestStatus();
    // return 0;
}