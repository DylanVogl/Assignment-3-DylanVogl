#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "../code_1/browserHistory.hpp"

using namespace std;

void displayMenu();

int main(int argc, char *argv[])
{
    BrowserHistory browserHistory;
    // DO NOT MODIFY THIS.
    if (argc > 1)
    {
        freopen(argv[1], "r", stdin);
    }
    // DO NOT MODIFY ABOVE.

    // TODO
    bool runMenu = true;
    int menuSelection;
    while (runMenu)
    {
        displayMenu();
        cin >> menuSelection;
        while(cin.fail() || (menuSelection < 1 || menuSelection > 6)){
        cout << "Invalid input" << endl;
        cin.clear();
        cin.ignore(10000, 10);
        cin >> menuSelection;
        }
        switch (menuSelection)
        {
        case 1:
            browserHistory.buildBrowserHistory();
            browserHistory.displayHistory();
            break;
        case 2:
            browserHistory.displayHistory();
            break;
        case 3:
        {
            string newUrl;
            int newId;
            string previousUrl;
            WebPage *ptrNewWP = new WebPage;
            WebPage *ptrPreviousWP = nullptr;
            cout << "Enter the new web page's url:" << endl;
            cin >> newUrl;
            bool isNewId = false;
            while (!isNewId)
            {
                cout << "Enter the new web page's id:" << endl;
                cin >> newId;
                if (browserHistory.searchPageByID(newId) == nullptr)
                    isNewId = true;
                else
                    cout << "This ID already exists. Try again.\n";
            }
            bool isPreviousUrl = false;
            while (!isPreviousUrl)
            {
                cout << "Enter the previous page's url (or First):" << endl;
                cin >> previousUrl;
                if (previousUrl == "First")
                    isPreviousUrl = true;
                else if (browserHistory.searchPageByURL(previousUrl) != nullptr)
                    isPreviousUrl = true;
                else
                    cout << "INVALID(previous page url)... Please enter a VALID previous page url!" << endl;
            }
            ptrNewWP->id = newId;
            ptrNewWP->views = 0;
            ptrNewWP->url = newUrl;
            ptrNewWP->owner = "";
            ptrNewWP->next = nullptr;

            if (previousUrl != "First")
                ptrPreviousWP = browserHistory.searchPageByURL(previousUrl);

            browserHistory.addWebPage(ptrPreviousWP, ptrNewWP);
            break;
        }
        case 4:
        {
            bool pageFound = false;
            string addOwnerUrl;
            string owner;
            while (!pageFound)
            {
                cout << "Enter url of the web page to add the owner: " << endl;
                cin >> addOwnerUrl;
                if (browserHistory.searchPageByURL(addOwnerUrl) != nullptr)
                    pageFound = true;
                else
                    browserHistory.addOwner(addOwnerUrl, owner);
            }
            cout << "Enter the owner: ";
            cin.ignore(10000, 10);
            getline(cin, owner);
            browserHistory.addOwner(addOwnerUrl, owner);
            break;
        }
        case 5:
        {
            string viewCountUrl;
            bool pageFound = false;
            WebPage *ptrPageViews = nullptr;
            while (!pageFound)
            {
                cout << "Enter url of the web page to check the view count: " << endl;
                cin >> viewCountUrl;
                if (browserHistory.searchPageByURL(viewCountUrl) != nullptr)
                    pageFound = true;
                else
                    cout << "Page not found. Try again." << endl;
            }
            ptrPageViews = browserHistory.searchPageByURL(viewCountUrl);
            cout << "View count for URL - " << viewCountUrl << " is " << ptrPageViews->views << endl;
            break;
        }
        case 6:
            cout << "Quitting...Goodbye!" << endl;
            runMenu = false;
            break;
        }
    }
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
