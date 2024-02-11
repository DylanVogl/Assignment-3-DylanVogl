/*************************************************************/
/*                BrowserHistory Definition                  */
/*************************************************************/
/* TODO: Implement the member functions of BrowserHistory    */
/*     This class uses a linked-list of WebPage structs to   */
/*     represent the schedule of web pages                   */
/*************************************************************/

#include "browserHistory.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
BrowserHistory::BrowserHistory() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool BrowserHistory::isEmpty() {
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: prints the current list of pages 
 * in the given format.
 * [ID::1]-(URL::url1) -> ... -> NULL
 * @param none
 * @return none
 */
void BrowserHistory::displayHistory() {
    // TODO
    WebPage *current = head;
    cout << "== CURRENT BROWSER HISTORY ==" << endl;
    while(current != nullptr)
    {
        cout << "[ID:: " << current->id << "]-(URL::" << current->url << ") -> ";
        current = current->next;
    }
    if(isEmpty())
    {
        cout << "Empty History" << endl;
    }
    cout << "NULL" << endl;
    cout << "===" << endl;
}

/*
 * Purpose: Add a new webpage to the browser history LL
 *   between the previous and the page that follows it in the list.
 * @param previousPage, the show that comes before the new page
 * @param newPage, the webpage to be added. 
 * @return none
 */
void BrowserHistory::addWebPage(WebPage* previousPage, WebPage* newPage) {
    // TODO
    cout << "adding: ["<< newPage->id << "]-" << newPage->url;
    if (previousPage == nullptr) { /* inserting a new head node */
        newPage->next = head;
        head = newPage;
        cout << " (HEAD)" << endl;
    }
    else if (previousPage->next == nullptr) { /* inserting a new tail node */
        previousPage->next = newPage;
        cout << " (prev: [" << previousPage->id << "])" << endl;
        if(head == 0)
            head = newPage;
    }
    else { /* inserting a node in the middle */
        newPage->next = previousPage->next;
        previousPage->next = newPage;
        cout << " (prev: [" << previousPage->id << "])" << endl;
    }
}

/*
 * Purpose: populates the BrowserHistory with the predetermined pages
 * @param none
 * @return none
 */
void BrowserHistory::buildBrowserHistory() {
    // TODO
    WebPage webPages[5];
    WebPage *ptrPage1 = nullptr;
    ptrPage1 = &webPages[0];
    WebPage *ptrPage2 = nullptr;
    ptrPage2 = &webPages[1];
    WebPage *ptrPage3 = nullptr;
    ptrPage3 = &webPages[2];
    WebPage *ptrPage4 = nullptr;
    ptrPage4 = &webPages[3];
    WebPage *ptrPage5 = nullptr;
    ptrPage5 = &webPages[4];
    ptrPage1->url = "https://www.colorado.edu/";
    ptrPage2->url = "https://www.wikipedia.org/";
    ptrPage3->url = "https://brilliant.org/";
    ptrPage4->url = "https://www.khanacademy.org/";
    ptrPage5->url = "https://www.numberphile.com/";
    ptrPage1->id = 10;
    ptrPage2->id = 11;
    ptrPage3->id = 12;
    ptrPage4->id = 13;
    ptrPage5->id = 14;

    addWebPage(searchPageByURL("First"), ptrPage1);
    addWebPage(ptrPage1, ptrPage2);
    addWebPage(ptrPage2, ptrPage3);
    addWebPage(ptrPage3, ptrPage4);
    addWebPage(ptrPage4, ptrPage5);
}


/*
 * Purpose: Search the BrowserHistory for the specified 
 * web page by ID and return a pointer to that node.
 * @param int id - ID of the web page to look for in LL.
 * @return pointer to node of page, or NULL if not found
 *
 */
WebPage* BrowserHistory::searchPageByID(int id) {
    // TODO
    WebPage *current = head;
    while(current != nullptr)
    {
        if(current->id == id)
        {
            return current;
        }
        current = current->next;
    }
    cout << "Page not found. Try again." << endl;
    return nullptr;
}


/*
 * Purpose: Search the BrowserHistory for the specified 
 * web page by the URL and return a pointer to that node.
 * @param string url - url of the web page to look for in LL.
 * @return pointer to node of page, or NULL if not found
 *
 */
WebPage* BrowserHistory::searchPageByURL(std::string url) {
    // TODO
    WebPage *current = head;
    if(url != "First")
    {
        while(current != nullptr )
        {
            if(current->url == url)
            {
                return current;
            }
            current = current->next;
        }
        cout << "Page not found. Try again." << endl;
        return nullptr;
    }
    else
    {
        return head->next;
    }
}

/*
 * Purpose: Give an owner to a web page.
 * @param receiver - name of the show that is receiving the rating
 * @param rating - the rating that is being given to a show
 * @return none
 */
void BrowserHistory::addOwner(std::string url, string owner) {
    // TODO
    WebPage *current = searchPageByURL(url);
    current->owner = owner;
}

void BrowserHistory::updateViews(string url) {
    // TODO
    searchPageByURL(url)->views += 1;
}
