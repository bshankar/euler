#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef unsigned int ui;

/* Quick and dirty implementation of
 * dancing links algorithm for efficiently 
 * solving exact cover problems
 */

#define INFTY 500000
typedef vector<vector<bool> > vvb;

typedef struct link {
    link *left;
    link *right;
    link *up;
    link *down;

    link *coln;

    ui name;
    ui size;
}* node;


class dlx {
public:
    dlx(const vvb& matrix, void (*printPtr)(node*));
    void initLinks(const vvb& matrix);
    ~dlx();

    void chooseColn();
    void cover(node c);
    void uncover(node c);
    void search(ui depth);
    void printSolution();

private:
    void ( *printPtr) (node*);
    node solution[INFTY];
    node root;
    node thisHead;
    node tmpHead;
    node tmpRow;
    vector<node> colnHeaders;
    ui minSize;
    node minColn;
};

