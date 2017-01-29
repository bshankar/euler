#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
typedef unsigned char uchar;

#define CLUES 6
#define SIZE 5

typedef struct link {
    link *up;
    link *down;
    link *left;
    link *right;

    uchar value;
    bool dead;
}* node;

/*
 * An interesting data structure to contain all the 
 * rules. The clues is a matrix of nodes looks like this
 *=============================================
 * 0    cr1   cr2   cr3        0
 *
 * m1  c[0]  c[1]  c[2] ... c[SIZE-1]
 *
 * m2  c[1]  ...
 *
 * ...
 *
 * m_
 *=============================================
 * where cr1 cr2 ... are no of correlated elements in the column
 * m1, m2 ... are # of matches for each clue
 * c[0] ... c[SIZE-1] is the clue
 *
 * This matrix is linked
 *                crk
 * ...             ||
 * m <-> c[0] ... c[k] <-> c[k+1]
 *                 ||
 * m_             c_[k]
 *
 * where c_[k] and c[k] are correlated.
 * The answer is linked in a similar way.
 * s <-> a[0] <-> ... a[SIZE-1] 
 */


struct state {
    node clues[SIZE+1][CLUES+1]; // must be transposted for efficient searching
    node ans[SIZE+1];

    // total number of correlations and matches
    node root;
    uchar corr;
};


void markDead(state *s) {
    // some clues cannot be 
    // part of the solution space
    // mark them dead
    for (node c = s->root->right; c != s->root; c = c->right)
        if (!c->value)
            for (node r = c->down; r != c; r = r->down)
                for (node r_ = r->right; r_ != r; r_ = r_->right)
                    if (r->value == r_->value) {
                        r->dead = true;
                        r_->dead = true;
                    }
}


void initLinks(state *s) {

    s->root = s->clues[0][0];

    // vertical links for clues
    for (int i = 1; i < SIZE+1; ++i) {
        for (int j = 0; j < CLUES+1; ++j) {
            s->clues[i][j]->up = s->clues[i][j-1];
            s->clues[i][j-1]->down = s->clues[i][j];
        }
    }

    // make vertical links circular
    for (int i = 0; i < CLUES+1; ++i) {
        s->clues[SIZE][i]->down = s->clues[0][i];
        s->clues[0][i]->up = s->clues[SIZE][i];
    }

    // horizontal links for for ans
    for (int i = 1; i < SIZE+1; ++i) {
        s->ans[i]->left = s->ans[i-1];
        s->ans[i-1]->right = s->ans[i];
    }

    // make ans circular
    s->ans[SIZE]->right = s->ans[0];
    s->ans[0]->left = s->ans[SIZE];

    // horizontal links for correlations
    for (uchar d = 0; d < 10; ++d) 
        for (int k = 1; k < SIZE+1; ++k) 
            for (int i = 1; i < CLUES+1; ++i) 
                for (int j = i+1; j < CLUES+1; ++j) 
                    if (s->clues[k][i]->value == d && 
                        s->clues[k][i]->value == s->clues[k][j]->value &&
                        !s->clues[k][i]->dead) {
                        // link vertically two correlated nodes
                        s->clues[k][i]->right = s->clues[k][j];
                        s->clues[k][j]->left = s->clues[k][i];
                        ++s->clues[k][0]->value;
                        cout << k << i << j << (int) d;
                        cout << (int) s->clues[k][0]->value << endl;
                        // update i
                        i = j;
                    }


    // horizontal links for column headers
    for (int i = 1; i < CLUES+1; ++i) {
        s->clues[0][i]->left = s->clues[0][i-1];
        s->clues[0][i-1]->right = s->clues[0][i];
    }

    s->clues[0][0]->left = s->clues[0][CLUES];
    s->clues[0][CLUES]->right = s->clues[0][0];

    // make horizontal links circular
    for (int d = 0; d < 10; ++d)
        for (int i = 1; i < SIZE+1; ++i)
            for (int j = 1; j < CLUES+1; ++j) {
                node n = s->clues[i][j];
                node n_ = n;
                while (n->right != NULL && n->right != n_)
                    n = n->right;

                n_->left = n;
                n->right = n_;
            }

    // update corr
    for (int i = 1; i < SIZE+1; ++i)
        s->corr += s->clues[i][0]->value;
    cout << (int) s->corr << endl;
    // update matches
    for (int i = 1; i < CLUES+1; ++i)
        s->clues[0][0]->value += s->clues[0][i]->value;

    markDead(s);
};


void printAns(state *s) {
    for (int i = 0; i < SIZE; ++i)
        cout << (int) s->ans[i]->value;
    cout << endl;
}


void findMin(state *s) {
}


void search(state *s) {

    if (!s->ans[0]->value) {
        printAns(s);
        return;
    }

    findMin(s);
    search(s);
}


int main(int argc, const char *argv[]) {
    ifstream file("185_test.txt");

    // allocate the state struct
    state *s = new state;
    for (int i = 0; i < SIZE+1; ++i) {
        s->ans[i] = new link;
        for (int j = 0; j < CLUES+1; ++j)
            s->clues[i][j] = new link;
    }

    // read data into s
    string str; int m;
    for (int i = 1; i < CLUES+1; ++i) {
        file >> str >> m;
        s->clues[0][i]->value = m;
        for (int j = 1; j < SIZE+1; ++j) {
            s->clues[j][i]->value = str[j-1] - '0';
        }
    }

    initLinks(s);
    delete s;
}
