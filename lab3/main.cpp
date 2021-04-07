#include <iostream>
#include "GroundRace.h"
#include "MixedRace.h"
#include "AirRace.h"

int main() {
    try{
        Broom broom1("HarryPotter");
        Centaur centaur1("TotChelIzHarryPottera");
        Mortar mortar1("BabaYaga");
        SpeedCamel speedCamel1("DominicToretto");
        BactrianCamel bactrianCamel1("SomeTwins");
        AllTerrainBoots allTerrainBoots1("StariySopogDeda");
        MagicCarpet magicCarpet1("KoverSoSteniDeda");

        vector<FlyingTransport *> participants1;
        participants1.push_back(&broom1);
        participants1.push_back(&mortar1);
        participants1.push_back(&magicCarpet1);

        vector<GroundTransport *> participants2;
        participants2.push_back(&centaur1);
        participants2.push_back(&speedCamel1);
        participants2.push_back(&bactrianCamel1);
        participants2.push_back(&allTerrainBoots1);

        vector<Transport *> participants3;
        participants3.push_back(&broom1);
        participants3.push_back(&mortar1);
        participants3.push_back(&magicCarpet1);
        participants3.push_back(&centaur1);
        participants3.push_back(&speedCamel1);
        participants3.push_back(&bactrianCamel1);
        participants3.push_back(&allTerrainBoots1);

        double distance;
        cout << "Please set the distance of race." << endl;
        cin >> distance;
        AirRace newAirRace(distance);
        MixedRace newMixedRace(distance);
        GroundRace newGroundRace(distance);
        vector<Transport *> winnersMixed = newMixedRace.runTheRace(participants3);
        vector<FlyingTransport *> winnersAir = newAirRace.runTheRace(participants1);
        vector<GroundTransport *> winnersGround = newGroundRace.runTheRace(participants2);
        if(winnersMixed.size() == 0){
            throw (string) "Ti Durak";
        }
        if(winnersMixed.size() == 1){
            cout << "The winner is " << winnersMixed[0]->myTransportName() << " which rider is " << winnersMixed[0]->getMyRiderName();
        }
        if(winnersMixed.size() > 1){
            cout << "We have more than 1 winner today!!!" << endl;
            for (auto participant : winnersMixed) {
                cout << "The winner is " << participant->myTransportName() << " which rider is " << participant->getMyRiderName() << endl;
            }
        }
    } catch (string &exception) {
        std::cerr << "Error: " << exception << '\n';
        return 1;
    }
    return 0;
}
