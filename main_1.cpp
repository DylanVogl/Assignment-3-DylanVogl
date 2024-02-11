#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "../code_1/browserHistory.hpp"

using namespace std;

void displayMenu();

int main(int argc, char* argv[]) {

    // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
    // DO NOT MODIFY ABOVE.
    fclose(stdin);
    // TODO
    BrowserHistory browserHistory;
    ifstream file (argv[1]);
    string line;
    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file, line);
            if(line == "1")
            {
                browserHistory.buildBrowserHistory();
            }
            else if(line == "2")
            {
                browserHistory.displayHistory();
            }
            else if(line == "3")
            {
                string newUrl;
                string newId;
                string oldUrl;
                getline(file, newUrl);
                getline(file, newId);
                getline(file, oldUrl);
                WebPage newWP;
                newWP.url = newUrl;
                newWP.id = stoi(newId);
                browserHistory.addWebPage(browserHistory.searchPageByURL(oldUrl), &newWP);
            }
            else if(line == "4")
            {
                string addOwnerUrl;
                string owner;
                getline(file, addOwnerUrl);
                while(browserHistory.searchPageByURL(addOwnerUrl) == nullptr)
                {
                    getline(file, addOwnerUrl);
                }
                getline(file, owner);
                browserHistory.addOwner(addOwnerUrl, owner);
            }
            else if(line == "5")
            {
                string viewCountUrl;
                getline(file, viewCountUrl);
                while(browserHistory.searchPageByURL(viewCountUrl) == nullptr)
                {
                    getline(file, viewCountUrl);
                }
                cout << browserHistory.searchPageByURL(viewCountUrl)->views << endl;
            }
            else if(line == "6")
            {
                return -1;
            }
        }
    }
    file.close();
    
    return 0;
}




/************************************************
           Definitions for main_1.cpp
************************************************/
void displayMenu()
{
    // COMPLETE: You DO NOT need to edit this
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build history " << endl;
    cout << " 2. Display history " << endl;
    cout << " 3. Add web page " << endl;
    cout << " 4. Add owner" << endl;
    cout << " 5. View count for a web page" << endl;
    cout << " 6. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
