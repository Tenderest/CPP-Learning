// stkoptr1.cpp -- testing stack of pointers
#include <iostream>
#include <cstdlib> // for rand(), srand()
#include <ctime>   // for time()
#include "stcktp1.h"
const int Num = 10;

int main(void)
{
        std::srand(std::time(0)); // randomize rand() 随机rand ()
        std::cout << "Please enter stack size: ";
        int stacksize;
        std::cin >> stacksize;
        // create an empty stack with stcksize slots
        Stack<const char *> st(stacksize);

        const char * in[Num] = {
                " !: Hank Gilgamesh", " 2: Kiki Ishtar",
                " 3: Betty Rocker",   " 4: Ian Flagranti",
                " 5: Wolfgang Kibble", " 6: Portia Koop",
                " 7: Joy Almondp",    " 8: Xaverie Paprika",
                " 9: Jan Moore",      " 10: Misha Mach"
        };

        // out basket
        const char * out[Num];

        int processed = 0;
        int nextin = 0;
        while ( processed < Num )
        {
                if ( st.isempty() )
                {
                        st.push(in[nextin ++]);
                }
                else if ( st.isfull() )
                {
                        st.pop(out[processed ++]);
                }
                else if ( std::rand() % 2 && nextin < Num )
                {
                        st.push(in[nextin ++]);
                }
                else
                {
                        st.pop(out[processed ++]);
                }
        }
        for ( int i = 0; i < Num; i ++ )
        {
                std::cout << out[i] << std::endl;
        }
        
        std::cout << "Bye\n";
        return 0;
}
