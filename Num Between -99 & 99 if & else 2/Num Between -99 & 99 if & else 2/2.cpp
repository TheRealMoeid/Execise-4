#include <iostream>
#include <map>
#include <string>

using namespace std;


int main() {
    int Input_num;

    const string O = " o "; 
    string number_str = "";

    map<int, string> yekan = {
        {0, "sefr"}, {1, "yek"}, {2, "do"}, {3, "se"}, {4, "char"},
        {5, "panj"}, {6, "Shish"}, {7, "haft"}, {8, "hasht"}, {9, "noh"}
    };
    map<int, string> khas = {
        {10, "dah"}, {11, "yazdah"}, {12, "davazdah"}, {13, "sizdah"}, {14, "chardah"},
        {15, "punzdah"}, {16, "shunzdah"}, {17, "hefdah"}, {18, "hejdah"}, {19, "nuzdah"}
    };
    map<int, string> dahgun = {
        {20, "bist"}, {30, "si"}, {40, "chel"}, {50, "panja"},
        {60, "shast"}, {70, "haftad"}, {80, "hashtad"}, {90, "navad"}
    };

    while (true) {
        cout << "Please give a Num between -99 and 99: ";
        cin >> Input_num;

       
        if (Input_num < -99 || Input_num > 99) {
            cout << "Wrong input, please try again...\n";
            continue; 
        }

        number_str = ""; 

        int abs_num = abs(Input_num); 
        int NumYekan = abs_num % 10;  
        int NumDahgun = abs_num / 10; 

        if (Input_num == 0) {
           
            number_str = yekan[0];
        }
        else if (Input_num < 0) {
            
            number_str += "manfie ";

            abs_num = abs(Input_num); 
            NumYekan = abs_num % 10;
            NumDahgun = abs_num / 10;
        }

        if (abs_num >= 10 && abs_num <= 19) {
            
            number_str += khas[abs_num];
        }
        else if (abs_num >= 20 && abs_num <= 99) {
           
            number_str += dahgun[NumDahgun * 10]; 
            if (NumYekan != 0) {
                number_str += O + yekan[NumYekan]; 
            }
        }
        else if (abs_num > 0 && abs_num <= 9) {
          
            number_str += yekan[abs_num];
        }

        cout << number_str << endl;
        break; 
    }

    return 0;
}
