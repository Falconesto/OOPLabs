#include "Action.h"

int main() {
    try {
        Action myAction;
        myAction.createNewShop(1, "Gucci", "Gucci str.");
        myAction.createNewShop(2, "Luis Vuitton", "Luis Vuitton str.");
        myAction.createNewShop(3, "Prada", "Prada str.");
        myAction.createNewItem(1, "Super Expensive Hat");
        myAction.createNewItem(2, "Super Expensive Shoes");
        myAction.createNewItem(3, "Super Expensive Scarf");
        myAction.createNewItem(4, "Super Expensive T-Shirt");
        myAction.createNewItem(5, "Super Expensive Pants");
        myAction.createNewItem(6, "Super Expensive Shirt");
        myAction.createNewItem(7, "Other Super Expensive Stuff");

        myAction.supplyShopWithItem(1, 1, 100, 1000);
        myAction.supplyShopWithItem(1, 2, 10, 4000);
        myAction.supplyShopWithItem(1, 3, 50, 3000);
        myAction.supplyShopWithItem(1, 5, 40, 11500);
        myAction.supplyShopWithItem(1, 6, 48, 14500);
        myAction.supplyShopWithItem(2, 4, 70, 9000);
        myAction.supplyShopWithItem(2, 5, 120, 11000);
        myAction.supplyShopWithItem(2, 6, 40, 17000);
        myAction.supplyShopWithItem(3, 5, 80, 9000);
        myAction.supplyShopWithItem(3, 6, 30, 1000);
        myAction.supplyShopWithItem(3, 7, 220, 4000);

        cout << myAction.findTheCheapestWithinShops(5) << endl << endl;

        myAction.howMuchItemsForMoney(1, 100000);
        cout << endl << endl;
        myAction.howMuchItemsForMoney(2, 100000);
        cout << endl << endl;
        myAction.howMuchItemsForMoney(3, 100000);
        cout << endl << endl;

        vector<pair<int, int>> batch;
        batch.push_back(make_pair(5, 35));
        batch.push_back(make_pair(6, 25));
        cout << myAction.buyBatchOfItems(batch, 2, true) << endl << endl;

        cout << myAction.findCheapestBatchInShops(batch) << endl;

    } catch (string &exception) {
        std::cerr << "Error: " << exception << '\n';
        return 1;
    }
    return 0;
}
