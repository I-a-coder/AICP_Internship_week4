#include <iostream>
#include <string>

using namespace std;

// Structure to represent an item in the auction
struct AuctionItem 
{
    int itemNumber;
    string description;
    double reservePrice;
    double currentHighestBid;
    int numberOfBids;
};

// Function prototypes
void setupAuction(AuctionItem items[], int size);
void placeBid(AuctionItem items[], int size, int buyerNumber);
void endAuction(const AuctionItem items[], int size);

int main()
{
    const int numItems = 10;
    AuctionItem items[numItems];

    // Task 1: Auction set up
    setupAuction(items, numItems);

    // Task 2: Buyer bids
    int buyerNumber;
    do {
        cout << "Enter buyer number (enter 0 to end bidding): ";
        cin >> buyerNumber;
        if (buyerNumber != 0) {
            placeBid(items, numItems, buyerNumber);
        }
    } while (buyerNumber != 0);

    // Task 3: At the end of the auction
    endAuction(items, numItems);
    return 0;
}

// Function to set up the auction
void setupAuction(AuctionItem items[], int size) 
{
    cout << "Auction set up" << endl;
    for (int i = 0; i < size; ++i) 
    {
        cout << "Enter details for item " << i + 1 << ":" << endl;
        cout << "Item number: ";
        cin >> items[i].itemNumber;
        cout << "Description: ";
        cin.ignore();
        getline(cin, items[i].description);
        cout << "Reserve price: ";
        cin >> items[i].reservePrice;
        items[i].currentHighestBid = 0.0;
        items[i].numberOfBids = 0;
    }
}

// Function to place a bid for an item
void placeBid(AuctionItem items[], int size, int buyerNumber) 
{
    int itemNumber;
    double bidAmount;

    cout << "Enter item number to bid for: ";
    cin >> itemNumber;

    for (int i = 0; i < size; ++i) {
        if (items[i].itemNumber == itemNumber) 
        {
            cout << "Enter your bid amount: $";
            cin >> bidAmount;
            if (bidAmount > items[i].currentHighestBid) 
            {
                items[i].currentHighestBid = bidAmount;
                items[i].numberOfBids++;
                cout << "Bid placed successfully." << endl;
            }
            else
            {
                cout << "Your bid must be higher than the current highest bid." << endl;
            }
            return;
        }
    }
    cout << "Item not found." << endl;
}

// Function to end the auction
void endAuction(const AuctionItem items[], int size) 
{
    double totalFee = 0.0;
    int itemsSold = 0;
    int itemsBelowReserve = 0;
    int itemsWithNoBids = 0;

    cout << "Auction Ended" << endl;
    for (int i = 0; i < size; ++i) 
    {
        if (items[i].currentHighestBid >= items[i].reservePrice) 
        {
            totalFee += 0.1 * items[i].currentHighestBid;
            itemsSold++;
        }
        else if (items[i].numberOfBids == 0) 
        {
            itemsWithNoBids++;
        }
        else 
        {
            itemsBelowReserve++;
        }
    }

    cout << "Total fee for sold items: $" << totalFee << endl;
    cout << "Items that didn't meet reserve: " << itemsBelowReserve << endl;
    cout << "Items with no bids: " << itemsWithNoBids << endl;
}
