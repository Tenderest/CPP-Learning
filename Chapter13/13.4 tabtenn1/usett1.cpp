// usett0.cpp -- using a base class
#include <iostream>
#include "tabtenn1.h"

int main(void)
{
        using std::cout;
        using std::endl;
        TableTennisPlayer player1("Tara", "Boomdea", false);
        RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
        rplayer1.Name(); // 派生对象使用基类方法 derived object uses base method
        if ( rplayer1.HasTable() )
        {
                cout << ": has a table.\n";
        }
        else
        {
                cout << ": hasn't a table.\n";
        }
        player1.Name();  // 基类对象使用基类方法 base object uses base method
        if ( player1.HasTable() )
        {
                cout << ": has a table.\n";
        }
        else
        {
                cout << ": hasn't a table.\n";
        }
        cout << "Name: ";
        rplayer1.Name();
        cout << "; Rating: " << rplayer1.Rating() << endl;
        // 使用TableTennisPlayer对象初始化RatingPlayer
        // initialize RatedPlayer using TableTennisPlayer object
        // player1是TableTennisPlayer对象
        RatedPlayer rplayer2(1212, player1);
        cout << "Name: ";
        rplayer2.Name();
        cout << "; Rating: " << rplayer2.Rating() << endl;

        return 0;
}
