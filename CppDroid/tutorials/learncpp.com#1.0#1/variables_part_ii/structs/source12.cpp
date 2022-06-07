#include <iostream>

// First we need to define our Advertising struct
struct Advertising
{
    int nAdsShown;
    float fClickThroughRate; // as a %
    float fAverageEarningsPerClick;
};

void PrintAdvertising(Advertising sAd)
{
    using namespace std;
    cout << "Number of ads shown: " << sAd.nAdsShown << endl;
    cout << "Click through rate: " << sAd.fClickThroughRate << endl;
    cout << "Average earnings per click: $" << sAd.fAverageEarningsPerClick << endl;

    // The following line is split up to reduce the length
    cout << "Total Earnings: $" <<
        (sAd.nAdsShown * sAd.fClickThroughRate * sAd.fAverageEarningsPerClick) << endl;
}

int main()
{
    using namespace std;
    // Declare an Advertising struct variable
    Advertising sAd;

    cout << "How many ads were shown today? ";
    cin >> sAd.nAdsShown;
    cout << "What was the click through rate? ";
    cin >> sAd.fClickThroughRate;
    cout << "What was the average earnings per click? ";
    cin >> sAd.fAverageEarningsPerClick;

    PrintAdvertising(sAd);
    return 0;
}