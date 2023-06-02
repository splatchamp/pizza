//
// Created by splat on 1/15/2023.
//

#include <iostream>
#include <tgmath.h>
#include <iomanip>
using std::cout, std::endl, std::cin, std::pow, std::pow;

const int LARGE_FED = 7;
const int MEDIUM_FED = 3;
const int SMALL_FED = 1;

const double PI = 3.14159265;
const int LARGE_DIAM = 20;
const int MEDIUM_DIAM = 16;
const int SMALL_DIAM= 12;

const double LARGE_PRICE = 14.68;
const double MEDIUM_PRICE = 11.48;
const double SMALL_PRICE = 7.28;

void pizza() {
    //Count Your Many Pizzas
    cout << "Please enter how many guests to order for: ";
    unsigned int n;
    cin >> n;

    unsigned int num_large = n / LARGE_FED;
    int remainder = n % LARGE_FED;

    unsigned int num_medium = remainder / MEDIUM_FED;
    remainder = remainder % MEDIUM_FED;

    unsigned int num_small = ceil(static_cast<double>(remainder) / SMALL_FED);

    cout << num_large << " large pizzas, " << num_medium <<
         " medium pizzas, and " << num_small << " small pizzas will be needed." <<
         endl << endl;

    //Serving Size
    double large_pizza_area = PI * std::pow((LARGE_DIAM / 2), 2);
    double medium_pizza_area = PI * std::pow((MEDIUM_DIAM / 2), 2);
    double small_pizza_area = PI * std::pow((SMALL_DIAM / 2), 2);
    double total_area = (large_pizza_area * num_large) +
                        (medium_pizza_area * num_medium) +
                        (small_pizza_area * num_small);

    double area_per_guest = total_area / n;

    cout << std::fixed << std::setprecision(2);
    cout << "A total of " << total_area << " square inches of pizza "
                                           "will be ordered (" <<
         area_per_guest << " per guest)." <<
         endl << endl;

    //Paying the Piper
    cout << "Please enter the tip as a percentage (i.e. 10 means 10%): ";
    double tip_percent;
    cin >> tip_percent;
    double total_before_tip = (num_large * LARGE_PRICE) + (num_medium * MEDIUM_PRICE) +
                              (num_small * SMALL_PRICE);
    double tip = tip_percent * 0.01 * total_before_tip;
    double total_cost = total_before_tip + tip;

    cout << std::setprecision(0);
    cout << "The total cost of the event will be: $" << std::fixed << std::trunc(std::round(total_cost)) << endl;
}

int main() {
    pizza();
}
